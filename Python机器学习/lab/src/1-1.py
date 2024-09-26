import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.datasets import load_diabetes

diabetes=load_diabetes()
print(diabetes.keys())
print(diabetes.feature_names)


dbt=pd.DataFrame(diabetes.data)
dbt

dbt_target=pd.DataFrame(diabetes.target)
dbt_target

from sklearn.model_selection import train_test_split
x = np.array(dbt.values)
y = np.array(dbt_target.values)
X_train,X_test,y_train,y_test=train_test_split(x,y,test_size=0.30)

from sklearn.linear_model import LinearRegression 
lr=LinearRegression(True, False, -1, False)
lr.fit(X_train,y_train)  

print ('求解截距项为：',lr.intercept_)  
print ('求解系数为：',lr.coef_)         


y_hat = lr.predict(X_test) 
y_hat[0:9]  

#y_test与y_hat的可视化
plt.figure(figsize=(10,6))  #设置图片尺寸
t = np.arange(len(X_test))  #创建t变量

plt.plot(t, y_test, 'r', linewidth=2, label='y_test') #绘制y_test曲线
plt.plot(t, y_hat, 'g', linewidth=2, label='y_hat')   #绘制y_hat曲线
plt.legend() #设置图例
plt.xlabel('test data')
plt.ylabel('price')
plt.show()

from sklearn import metrics
from sklearn.metrics import r2_score
# 拟合优度R2的输出方法一
print ("r2:",lr.score(X_test, y_test))  #基于Linear-Regression()的回归算法得分函数，来对预测集的拟合优度进行评价
# 拟合优度R2的输出方法二
print ("r2_score:",r2_score(y_test, y_hat)) #使用metrics的r2_score来对预测集的拟合优度进行评价
# 用scikit-learn计算MAE
print ("MAE:", metrics.mean_absolute_error(y_test, y_hat)) #计算平均绝对误差
# 用scikit-learn计算MSE
print ("MSE:", metrics.mean_squared_error(y_test, y_hat))  #计算均方误差
# # 用scikit-learn计算RMSE
print ("RMSE:", np.sqrt(metrics.mean_squared_error(y_test, y_hat))) #计算均方根误差


# # **三、考察每个特征值与结果之间的关联性，观察得出最相关的特征**
# 循环输出各特征值散点图
def mkPlt(idx, lbl):
    X = dbt.iloc[:,(idx):(idx+1)]
    Y = dbt_target

    plt.scatter(X, Y)
    plt.xlabel(lbl)
    plt.ylabel(u'Risk')
    plt.show()


for i in range (0, 10):
    mkPlt(i, diabetes.feature_names[i])


xr = np.array(dbt.iloc[:,[2, 3, 8]].values)
Xr_train,Xr_test,yr_train,yr_test=train_test_split(xr,y,test_size=0.30)


lrr= LinearRegression(copy_X=False, fit_intercept=True, n_jobs=-1, normalize=False)
lrr.fit(Xr_train,yr_train) #使用训练数据进行参数求解

yr_hat = lrr.predict(Xr_test) 
yr_hat[0:9]  

#y_test与y_hat的可视化
plt.figure(figsize=(10,6))  #设置图片尺寸
t = np.arange(len(Xr_test))  #创建t变量

plt.plot(t, yr_test, 'r', linewidth=2, label='yr_test') #绘制y_test曲线
plt.plot(t, yr_hat, 'g', linewidth=2, label='yr_hat')   #绘制y_hat曲线
plt.legend() #设置图例
plt.xlabel('test data')
plt.ylabel('Risk')
plt.show()

# 拟合优度R2的输出方法一
print ("r2:",lrr.score(Xr_test, yr_test))  #基于Linear-Regression()的回归算法得分函数，来对预测集的拟合优度进行评价
# 拟合优度R2的输出方法二
print ("r2_score:",r2_score(yr_test, yr_hat)) #使用metrics的r2_score来对预测集的拟合优度进行评价
# 用scikit-learn计算MAE
print ("MAE:", metrics.mean_absolute_error(yr_test, yr_hat)) #计算平均绝对误差
# 用scikit-learn计算MSE
print ("MSE:", metrics.mean_squared_error(yr_test, yr_hat))  #计算均方误差
# # 用scikit-learn计算RMSE
print ("RMSE:", np.sqrt(metrics.mean_squared_error(yr_test, yr_hat))) #计算均方根误差

print ('求解截距项为：',lrr.intercept_)  
print ('求解系数为：',lrr.coef_)