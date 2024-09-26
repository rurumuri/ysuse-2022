import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report
from sklearn.svm import SVC

# 数据读取
dataset = pd.read_csv("data/data74924/data.csv")
dataset.replace({'B':0, 'M':1}, inplace=True)
dataset.head()

data=dataset.iloc[:,1:12]
data.head()

# 热力图绘制
import matplotlib.pyplot as plt
import seaborn as sns
corr = data.corr()
corr

ax = plt.subplots(figsize=(10, 8))
ax = sns.heatmap(corr, vmax=.8, square=True, annot=True)
plt.xticks(fontsize=20)
plt.yticks(fontsize=20)

# 数据切片、清洗
data=data.loc[:,['diagnosis', 'radius_mean', 'perimeter_mean', 'area_mean','concavity_mean','concave points_mean']]
data

from sklearn.model_selection import train_test_split
from sklearn import preprocessing
x = data.iloc[:, 1:]
y = data.iloc[:, 0]
x = preprocessing.scale(x)
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size = 0.25)
x

# 模型训练
cl=SVC(kernel='linear', C = 10)
cl.fit(x_train, y_train)
prediction=cl.predict(x_test)
#查看分类效果
print('分类精度为：',cl.score(x_test,y_test)*100,'%')
print('评价指标：\n',classification_report(y_test,prediction))