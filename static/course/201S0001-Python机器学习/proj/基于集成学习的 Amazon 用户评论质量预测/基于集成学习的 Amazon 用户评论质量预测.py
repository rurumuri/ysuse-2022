# 以下是问题分析、模型构建和训练的部分

from sklearn.naive_bayes import MultinomialNB, BernoulliNB, ComplementNB, GaussianNB
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer
from sklearn import preprocessing, tree, ensemble, svm, metrics, calibration
from sklearn.model_selection import cross_val_score, train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import auc, accuracy_score
from sklearn.preprocessing import StandardScaler
from sklearn.feature_extraction import text
from matplotlib import pyplot as plt
from itertools import combinations
from wordcloud import WordCloud
from collections import Counter
from textblob import TextBlob
from tqdm import tqdm
import pandas as pd
import numpy as np
import random
import math
import shap
import nltk

# A 问题分析、模型构建和训练
## 训练数据加载和预处理
### 数据加载和特征提取
train_df = pd.read_csv("./data/train.csv", sep='\t')
train_df['lenth'] = train_df['reviewText'].map(lambda x:len(x.split(" ")))
train_df['polarity'] = train_df['reviewText'].map(lambda x: TextBlob(x).sentiment[0])

### 数据划分
def train_test_split(data, test_size=0.3, shuffle=True, random_state=None):
    train = data[int(len(data)*test_size):].reset_index(drop=True)
    test = data[:int(len(data)*test_size)].reset_index(drop=True)
    return train, test

train_df, test_df = train_test_split(train_df, test_size=0.3)

### 数据预览
train_df.shape

train_df.describe()

test_df.shape

test_df.describe()

### 特征分析和选取

for co in ['votes_all', 'votes_up', 'reviewerID', 'asin', 'overall', 'lenth', 'polarity']:
    a = Counter(train_df[co])  # 统计整个数据集中特征列的频次
    t = Counter(train_df[train_df['label'] == 1][co])  # 统计label为1的子集中特征列的频次
    f = Counter(train_df[train_df['label'] == 0][co])  # 统计label为0的子集中特征列的频次

    plt.figure(figsize=(10, 4))
    
    # 绘制第一个子图
    plt.subplot(121)
    plt.scatter(a.keys(), a.values(), label='All', color='blue', alpha=0.5)
    plt.scatter(t.keys(), t.values(), label='Label 1', color='green', alpha=0.5)
    plt.legend()
    plt.title('All vs Label 1')
    plt.xlabel(co)
    plt.ylabel('Frequency')
    
    # 绘制第二个子图
    plt.subplot(122)
    plt.scatter(a.keys(), a.values(), label='All', color='blue', alpha=0.5)
    plt.scatter(f.keys(), f.values(), label='Label 0', color='red', alpha=0.5)
    plt.legend()
    plt.title('All vs Label 0')
    plt.xlabel(co)
    plt.ylabel('Frequency')

    # 设置整体标题
    plt.suptitle(co)
    plt.tight_layout(rect=[0, 0.03, 1, 0.95])
    plt.show()

### reviewText向量化处理

def vectorize(train_data, test_data=None, min_df=0.019, max_df=1.0, max_features=5000, stop_words='english', method='tfidf'):
    if method == 'count':
        cv = CountVectorizer(
            min_df=min_df, max_df=max_df, max_features=max_features, stop_words=stop_words)
    elif method == 'tfidf':
        cv = TfidfVectorizer(min_df=min_df, max_df=max_df,
                             max_features=max_features, stop_words=stop_words, ngram_range=(1, 1))
    cv_model = cv.fit(train_data)
    names = cv_model.get_feature_names_out()
    features = cv.transform(train_data).toarray()
    feature_lst = []
    feature_lst.append(features)
    # if valid_data:
    #     va_features = cv.transform(valid_data).toarray()
    #     feature_lst.append(va_features)
    if not test_data.empty:
        te_features = cv.transform(test_data).toarray()
        feature_lst.append(te_features)
    return names, feature_lst


names, fea_lst = vectorize(train_df['reviewText'], test_df['reviewText'])
features, te_features = fea_lst[0], fea_lst[1]
print(features.shape, te_features.shape)

### 停用词筛选


# 词云绘制函数
def draw_cloud(features, names, limits_count=100):
    """
    绘制词云，可视化
    """
    df = pd.DataFrame(features, columns=names)
    df.describe()
    word_counts = dict(df.mean())
    
    # 绘制词云
    my_cloud = WordCloud(
        background_color='black',  # 设置背景颜色为黑色
        width=900, height=600,
        max_words=limits_count,   # 词云显示的最大词语数量
        font_path='simhei.ttf',   # 设置字体为SimHei
        max_font_size=99,         # 设置字体最大值
        min_font_size=16,         # 设置子图最小值
        random_state=50,          # 设置随机生成状态
        colormap='viridis'        # 设置词云颜色为Viridis配色
    ).generate_from_frequencies(word_counts)

    plt.figure(figsize=(12, 8))
    plt.imshow(my_cloud, interpolation='bilinear')
    plt.axis('off')
    plt.show()

draw_cloud(features,names)
# 通过上述两个规则筛选“停用词”，阈值为以100篇正负样本差和概率估计而出
def gen_stop(features, names, occ_thr=0.025, avg_thr=0.5):
    """
    features: trans array from raw vectorize
    names: features extracted from data, tobe selected
    occ_thr: the diff of frenquency of some feature in postive/nagtive is at least [occ_thr]
    avg_thr: the diff of occurrence(single review) of some feature in postive/nagtive is at least [avg_thr] 
    """
    features = pd.DataFrame(features,columns = names)
    pos, neg = features[train_df['label'].values ==
                        1], features[train_df['label'].values == 0]
    add_stop = []
    for name in names:
        p, n = pos[pos[name] != 0], neg[neg[name] != 0]
        if (abs(p.shape[0]/pos.shape[0] - n.shape[0]/neg.shape[0]) <= occ_thr and
            abs(p[name].sum()/p.shape[0] - n[name].sum()/n.shape[0] <= avg_thr)):
            add_stop.append(name)
    return add_stop

add_stop = gen_stop(features, names, occ_thr=0.03, avg_thr=0.5)
len(add_stop)

# 对新增停用词后的数据进行重新向量化
stop_words = text.ENGLISH_STOP_WORDS.union(add_stop)
names, fea_lst = vectorize(train_df['reviewText'], test_df['reviewText'], stop_words=list(stop_words))
features, te_features = fea_lst[0], fea_lst[1]
print(features.shape, te_features.shape)

draw_cloud(features,names)

## 模型构建
### 构造数据
X_train = np.concatenate(
    [features, train_df[['overall', 'lenth', 'polarity']]], axis=1)
X_train = preprocessing.MinMaxScaler().fit_transform(X_train)

X_test = np.concatenate(
    [te_features, test_df[['overall', 'lenth', 'polarity']]], axis=1)
X_test = preprocessing.MinMaxScaler().fit_transform(X_test)

### 构造基分类器
# 多种基分类器
clfs = dict()
clfs['LinearSVM'] = calibration.CalibratedClassifierCV(svm.LinearSVC(loss='squared_hinge', dual=False))
# clfs['SVC'] = svm.SVC(kernel='rbf', probability=True)
clfs['DecisionTree'] = tree.DecisionTreeClassifier(
    criterion='gini', max_depth=5, splitter='random')
clfs['MultBayes'] = MultinomialNB(alpha=1,fit_prior=True,class_prior=[0.8,0.2])
clfs['Knn'] = KNeighborsClassifier(n_neighbors=3)

from sklearn import calibration
for aa in tqdm(range(1)):
    clf = calibration.CalibratedClassifierCV(
        svm.LinearSVC(loss='squared_hinge', dual=False))
    clf.fit(X_train[:10000], train_df['label'][:10000])
    pre =clf.predict(X_train)
    # print(pre[1000:1100])
    print(accuracy_score(pre,train_df['label']))

### 构造集成框架
# 四种加权算法
def weight(results, labels, weights, y, cls_name, vote_thr=0.5):
    results, labels, weights = np.array(results).T, np.array(labels).T, np.array(weights)
    fig = plt.figure(figsize=(10, 10))
    pres = []
    # 算数平均法
    pre = np.average(results,axis=1)
    pres.append(pre)
    # 加权平均法
    pre = np.dot(results, weights)/np.sum(weights)
    pres.append(pre)
    # 多数投票法
    pre = np.average(labels, axis=1)
    # pre[pre > vote_thr], pre[pre <= vote_thr] = 1, 0
    pres.append(pre)
    # 加权投票法
    pre = np.dot(labels, weights)/np.sum(weights)
    # pre[pre > vote_thr], pre[pre <= vote_thr] = 1, 0
    pres.append(pre)
    # 绘图
    for idx, method in enumerate(['average', ' weight-average', 'vote', 'weight-vote']):
        pre = pres[idx]
        fpr, tpr, thresholds = metrics.roc_curve(y, pre, pos_label=1)
        plt.subplot(2, 2, idx+1)
        plt.plot(fpr, tpr, lw=2)
        auc = metrics.auc(fpr, tpr)
        pre[pre >= 0.5], pre[pre < 0.5] = 1, 0
        acc = accuracy_score(pre, y)
        plt.title('Method: %s    Auc: %.2f    Acc: %.2f' % (method, auc, acc))
        # print('Method: %s    Auc: %.2f    Acc: %.2f' % (method, auc, acc))
    plt.suptitle('Classifier: '+str(cls_name))

def bagging(base_estimators, datas, n_estimators=10, max_samples=0.1, max_features=0.5):

    assert (n_estimators>0 and max_samples>0 and max_features>0)
    results, labels, weights = [], [], []
    s0, s1 = datas[0].shape[0], datas[0].shape[1]
    for clf in base_estimators:
        for i in range(n_estimators):
            sample_lst = random.sample(range(s0), int(max_samples*s0))
            features_lst = random.sample(range(s1), int(max_features*s1))
            clf.fit(datas[0][sample_lst, :]
                    [:, features_lst], datas[1][sample_lst])
            pre = np.array(
                [p[1] for p in clf.predict_proba(datas[2][:, features_lst])])
            results.append(pre)

            th = np.sort(pre)[int(0.85*pre.shape[0])]

            pre[pre > th], pre[pre <= th] = 1, 0
            labels.append(pre)
            weights.append([accuracy_score(pre, datas[3])])
            # weights.append([cal_w(pre, datas[3])])
    return results, labels, weights

def adaboost(base_estimator, datas, n_estimators=50, learning_rate=1.0, algorithm='SAMME.R', max_samples=0.05, max_features=1.0):

    assert (n_estimators > 0 and max_samples > 0 and max_features > 0)
    """
    base_estimator: base model, only accept single
    datas: trainX, trainy, testX, testy
    n_estimators: the num of base_estimator, iterations
    learning_rate: the learning rate of algorithm
    【存疑】algorithm: 
        SAMME    cal the models'weight through the proba
        SAMME.R  cal the models'weight through the rate
    max_samples: float. The proportion of the sample
    max_features:  float. The proportion of the features
        
    """
    results, labels, weights = [], [], []
    s0, s1 = datas[0].shape[0], datas[0].shape[1]
    clf = base_estimator
    prob = np.array([1/s0 for n in range(s0)])
    for i in range(n_estimators):
        # 调整样本权重
        sample_lst = random.choices(
            range(s0), weights=prob, k=int(max_samples*s0))
        features_lst = random.sample(range(s1), int(max_features*s1))
        clf.fit(datas[0][sample_lst, :][:, features_lst], datas[1][sample_lst])
        mis_lst = np.array(clf.predict(datas[0][sample_lst, :][:, features_lst])) ^ datas[1][sample_lst]
        err = np.sum(prob[sample_lst][mis_lst==1])
        if err>0.5:
            print('ERROR more than half.')
            break
        prob[sample_lst][mis_lst == 1] *= learning_rate*err/(1-err)
        prob/=np.sum(prob)
        pre = np.array([p[1] for p in clf.predict_proba(datas[2][:, features_lst])])
        results.append(pre)
        # 根据比例生成预测标签，而不是根据预测概率
        th = np.sort(pre)[int(0.8*pre.shape[0])]
        # th = 0.5
        pre[pre > th], pre[pre <= th] = 1, 0
        labels.append(pre)
        weights.append(1/2*math.log((1-err)/err))
    return results, labels, weights

## 参数调优

train_df['votes_all'].describe()

les = np.where(train_df['votes_all'] < 14)[0]
mor = np.where(train_df['votes_all'] >= 14)[0]

print(train_df.columns)
print(test_df.columns)

for n in tqdm(range(1, len(clfs))):
    for names in combinations(clfs.keys(), n):
        results, labels, weights = bagging([clfs[name] for name in names], datas=[X_train[les], np.array(
            train_df['label'][les]), X_test, test_df['label']], n_estimators=8//n, max_samples=0.04, max_features=0.6)
        results_, labels_, weights_ = bagging([clfs[name] for name in names], datas=[X_train[mor], np.array(
            train_df['label'][mor]),  X_test, test_df['label']], n_estimators=8//n, max_samples=0.01, max_features=0.6)
        results+=results_
        labels+=labels_
        weights+=weights_
        # print(weights)
        weight(results, labels, weights, test_df['label'], '+'.join(names))

for name, clf in tqdm(clfs.items()):
    results, labels, weights = adaboost(clf, datas=[X_train[les], np.array(
        train_df['label'][les]), X_test], n_estimators=10, max_samples=1.0, max_features=1.0)
    results_, labels_, weights_ = adaboost(clf, datas=[X_train[les], np.array(
        train_df['label'][les]), X_test], n_estimators=10, max_samples=1.0, max_features=1.0)
    results += results_
    labels += labels_
    weights += weights_
    # print(weights)
    weight(results, labels, weights,
           test_df['label'], name)









# 以下是使用模型进行预测的部分

import pandas as pd
import numpy as np

train_df = pd.read_csv('./data/train.csv', sep='\t')
test_df = pd.read_csv('./data/test.csv', sep='\t')

import scipy
import sklearn
from sklearn.feature_extraction.text import TfidfVectorizer

# tf/idf 处理文本特征
word_model = TfidfVectorizer(stop_words='english')
train_X = word_model.fit_transform(train_df['reviewText'])
test_X = word_model.transform(test_df['reviewText']) 

# 拼上总评分特征
train_X = scipy.sparse.hstack([train_X, train_df['overall'].values.reshape((-1, 1)) / 5])
test_X = scipy.sparse.hstack([test_X, test_df['overall'].values.reshape((-1, 1)) / 5])

from sklearn import svm
from sklearn.tree import DecisionTreeClassifier
from sklearn.naive_bayes import BernoulliNB
from sklearn.calibration import CalibratedClassifierCV

def construct_clf(clf_name):
    clf = None
    if clf_name == 'SVM':
        clf = svm.LinearSVC()
    elif clf_name == 'DTree' :
        clf = DecisionTreeClassifier(max_depth=10, class_weight='balanced')
    elif clf_name == 'NB' :
        clf = BernoulliNB()
    # 概率校正，调整分类器的输出概率,使其更加准确地反映实际类别的概率分布。这样可以改善分类器在实际应用中的性能。
    clf = CalibratedClassifierCV(clf, cv=2, method='sigmoid')  
    return clf


class Bagging(object):
    def __init__(self, clf, num_iter):
        self.clf = clf  # 分类器对象
        self.num_iter = num_iter  # Bagging 的分类器个数
        
    def fit_predict(self, X, Y, test_X):
        result = np.zeros(test_X.shape[0])  # 记录测试集的预测结果
        train_idx = np.arange(len(Y))
        for i in range(self.num_iter):
            sample_idx = np.random.choice(train_idx, size=len(Y), replace=True)  # Bootstrap
            sample_train_X = X[sample_idx]
            sample_train_Y = Y[sample_idx]
            self.clf.fit(sample_train_X, sample_train_Y)
            print('Model {:>2d} finish!'.format(i))
            predict_proba = self.clf.predict_proba(test_X)[:, 1]
            result += predict_proba  # 累加不同分类器的预测概率
        result /= self.num_iter  # 取平均（投票）
        return result

class AdaBoostM1(object):
    def __init__(self, clf, num_iter):
        self.clf = clf  # 分类器对象
        self.num_iter = num_iter  # 迭代次数
        
    def fit_predict(self, X, Y, test_X):
        result_lst, beta_lst = list(), list()  # 记录每次迭代的预测结果和投票权重
        num_samples = len(Y)
        weight = np.ones(num_samples)  # 样本权重，注意总和应为 num_samples
        for i in range(self.num_iter):
            self.clf.fit(X, Y, sample_weight=weight)  # 带权重的 fit
            print('Model {:<2d} finish!'.format(i))
            train_predict = self.clf.predict(X)  # 训练集预测结果
            error_flag = train_predict != Y  # 预测错误的位置
            error = weight[error_flag].sum() / num_samples  # 计算错误率
            if error > 0.5:
                break
            beta = error / (1 - error)
            weight *= (1.0 - error_flag) * beta + error_flag  # 调整权重，正确位置乘上 beta，错误位置还是原来的
            weight /= weight.sum() / num_samples  # 归一化，让权重和等于 num_samples
            beta_lst.append(beta)
            predict_proba = self.clf.predict_proba(test_X)[:, 1]
            result_lst.append(predict_proba)
        beta_lst = np.log(1 / np.array(beta_lst))
        beta_lst /= beta_lst.sum()  # 归一化投票权重
        print('\nVote Weight:\n', beta_lst)
        result = (np.array(result_lst) * beta_lst[:, None]).sum(0)  # 每一轮的预测结果加权求和
        return result

np.random.seed(0) # 在训练机器学习模型时,设置固定的随机数种子可以确保模型的初始化状态每次都相同,有利于模型的收敛和性能评估。
clf = construct_clf('SVM')  # DTree, SVM, NB
# runner = Bagging(clf, 10)
runner = AdaBoostM1(clf, 10)
y_predict = runner.fit_predict(train_X.tocsr(), train_df['label'], test_X.tocsr())

# 生成提交测评的文件
result_df = pd.DataFrame()
result_df['Id'] = test_df['Id'].values
result_df['Predicted'] = y_predict
result_df.to_csv('./result.csv', index=False)

# 对参数进行组合，批量预测并导出结果
import os

clfs = ['SVM', 'DTree', 'NB']
n_esti = [10, 20, 30, 50]
os.mkdir("./result/");
for clf_name in clfs:
    for n in n_esti:
        clf = construct_clf(clf_name)  # 构造基学习器
        runner = AdaBoostM1(clf, n)  # 构造集成学习器
        y_predict = runner.fit_predict(train_X.tocsr(), train_df['label'], test_X.tocsr())  # 训练并预测
        result_df = pd.DataFrame()
        result_df['Id'] = test_df['Id'].values
        result_df['Predicted'] = y_predict
        os.mkdir("./result/result"+"_"+"ada"+"_"+clf_name+"_"+str(n));
        result_df.to_csv("./result/result"+"_"+"ada"+"_"+clf_name+"_"+str(n)+"/result.csv", index=False)

for clf_name in clfs:
    for n in n_esti:
        clf = construct_clf(clf_name)  # 构造基学习器
        runner = Bagging(clf, n)  # 构造集成学习器
        y_predict = runner.fit_predict(train_X.tocsr(), train_df['label'], test_X.tocsr())  # 训练并预测
        result_df = pd.DataFrame()
        result_df['Id'] = test_df['Id'].values
        result_df['Predicted'] = y_predict
        os.mkdir("./result/result"+"_"+"bag"+"_"+clf_name+"_"+str(n));
        result_df.to_csv("./result/result"+"_"+"bag"+"_"+clf_name+"_"+str(n)+"/result.csv", index=False)