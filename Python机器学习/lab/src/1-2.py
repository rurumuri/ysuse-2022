import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

fdata = pd.read_csv("./data/data72160/1_film.csv")
fdata

# 做散点图，观察数据特征
y = fdata.iloc[:,0]
x = fdata.iloc[:,1]

plt.scatter(x, y)
plt.xlabel(u'filmsize')
plt.ylabel(u'filmnum')
plt.show()

#绘制影厅人数数据集的散点图矩阵。
fig = plt.figure(figsize=(10, 15))
ax1 = fig.add_subplot(3, 1, 1)
ax1.set_xlabel(fdata.keys()[1])
ax1.set_ylabel(fdata.keys()[1])
ax1.scatter(x, y)

x = fdata.iloc[:,2]
ax2 = fig.add_subplot(3, 1, 2)
ax2.set_xlabel(fdata.keys()[2])
ax2.scatter(x, y)

x = fdata.iloc[:,3]
ax2 = fig.add_subplot(3, 1, 3)
ax2.set_xlabel(fdata.keys()[3])
ax2.scatter(x, y)

fig.show()

#选取特征变量与相应变量，并进行数据划分。
from sklearn.model_selection import train_test_split
X = np.array(fdata.iloc[:, 1:].values)  
y = np.array(fdata.iloc[:, 0].values)
X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.20)
X_train.shape,X_test.shape,y_train.shape,y_test.shape

#进行线性回归模型训练。
from sklearn.linear_model import LinearRegression
lr=LinearRegression()
lr.fit(X_train,y_train)

print ('求解截距项为：',lr.intercept_)
print ('求解系数为：',lr.coef_)

y_hat = lr.predict(X_test)
y_hat[0:9]


plt.figure(figsize=(10,6))
t = np.arange(len(X_test))

plt.plot(t, y_test, 'r', linewidth=2, label='y_test')
plt.plot(t, y_hat, 'g', linewidth=2, label='y_hat')
plt.legend()

plt.xlabel('test data')
plt.ylabel('price')
plt.show()

# 模型评估
from sklearn import metrics
from sklearn.metrics import r2_score

print ("r2:",lr.score(X_test, y_test))
print ("r2_score:",r2_score(y_test, y_hat)) 
print ("MAE:", metrics.mean_absolute_error(y_test, y_hat)) 
print ("MSE:", metrics.mean_squared_error(y_test, y_hat))
print ("RMSE:", np.sqrt(metrics.mean_squared_error(y_test, y_hat)))