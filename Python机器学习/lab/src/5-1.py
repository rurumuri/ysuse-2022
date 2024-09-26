import sklearn
from sklearn import datasets
from sklearn.ensemble import AdaBoostClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# 加载数据集并作分割
data = datasets.load_breast_cancer()
pd.DataFrame(data.data)

X = data.data
y = data.target
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.3)
print("训练集发生率：",y_train.sum() / y_train.size)
print("测试集发生率：",y_test.sum() / y_test.size)

# AdaBoost初步建模训练
clf = AdaBoostClassifier(n_estimators=2)
clf.fit(X_train, y_train)
predictions = clf.predict(X_test)
print('Accuracy:%s' % accuracy_score(y_test, predictions))
acc = np.empty([17])
acc[0] = accuracy_score(y_test, predictions)

# 调参：基分类器数目与准确率的关系
for i in range(1, 17):
    clf = AdaBoostClassifier(n_estimators=2 + 3 * i)
    clf.fit(X_train, y_train)
    predictions = clf.predict(X_test)
    acc[i] = accuracy_score(y_test, predictions)

# 作图
x = range(2, 51, 3)
y = acc
plt.plot(x,y,'s-',color = 'r',label="accuracy")
plt.xlabel("n_estimators")
plt.ylabel("accuracy")
plt.show()
