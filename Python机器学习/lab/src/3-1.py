from sklearn import datasets
import numpy as np
import pandas as pd

# 读取数据集，观察特征
bc = datasets.load_breast_cancer()
bc.feature_names
bc.target.shape

# 建模学习
from sklearn import tree
clf = tree.DecisionTreeClassifier()
clf.fit(bc.data[:350], bc.target[:350])
pred = clf.predict(bc.data[350:])
pred[:10] 

# 准确率评价
from sklearn.metrics import accuracy_score
print('Accuracy:%s'% accuracy_score(bc.target[350:], pred))

# 模型优化
clf_A = tree.DecisionTreeClassifier(criterion = 'entropy')
clf_A.fit(bc.data[:350], bc.target[:350])
pred_A = clf_A.predict(bc.data[350:])
pred_A[:10]
print('Accuracy:%s'% accuracy_score(bc.target[350:], pred_A))

clf_B = tree.DecisionTreeClassifier(max_depth=5)
clf_B.fit(bc.data[:350], bc.target[:350])
pred_B = clf_B.predict(bc.data[350:])
pred_B[:10]
print('Accuracy:%s'% accuracy_score(bc.target[350:], pred_B))

clf_C = tree.DecisionTreeClassifier(class_weight='balanced')
clf_C.fit(bc.data[:350], bc.target[:350])
pred_C = clf_C.predict(bc.data[350:])
pred_C[:10]
print('Accuracy:%s'% accuracy_score(bc.target[350:], pred_C))

clf_D = tree.DecisionTreeClassifier(max_features= 13, max_depth= 5, min_samples_split=4, max_leaf_nodes= 10)
clf_D.fit(bc.data[:350], bc.target[:350])
pred_D = clf_D.predict(bc.data[350:])
pred_D[:10]
print('Accuracy:%s'% accuracy_score(bc.target[350:], pred_D))