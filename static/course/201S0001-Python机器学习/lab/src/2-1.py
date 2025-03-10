import sklearn
import numpy as np
from sklearn import datasets, linear_model
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split

cancer = datasets.load_breast_cancer()
cancer
cancer.keys()


# 3. 打印查看数据集中标注好的肿瘤分类（target_names）、肿瘤特征名称（feature_names）。
print(cancer.target_names)
print(cancer.feature_names)

# 4. 将数据集拆分为训练集和测试集，打印查看训练集和测试集的数据形态（shape）。
x = np.array(cancer.data)
y = np.array(cancer.target)
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size = 0.25)

print(x_train.shape, y_train.shape)
print(x_test.shape, y_test.shape)


# 5.配置高斯朴素贝叶斯模型。

from sklearn.naive_bayes import GaussianNB 
model = GaussianNB()

# 6. 训练模型。
model.fit(x_train, y_train)

# 7. 评估模型，打印查看模型评分（分别打印训练集和测试集的评分）。

from sklearn.model_selection import cross_val_score
score_train = cross_val_score(model,x_train,y_train,cv=10,scoring='accuracy')
score_test = cross_val_score(model,x_test,y_test,cv=10,scoring='accuracy')
print("test set:", score_test.mean())
print("train set:", score_train.mean())


# 8.模型预测：选取某一样本进行预测。（可以进行多次不同样本的预测）
y_test
p_res = model.predict(x_test[1].reshape(1, -1))