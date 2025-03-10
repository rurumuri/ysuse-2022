import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from mpl_toolkits.mplot3d import Axes3D
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import classification_report,confusion_matrix

# 加载数据集
breast=load_breast_cancer()
data=breast['data']
target=breast['target']
feature_names=breast['feature_names']
df=pd.DataFrame(data,columns=feature_names)
df.head()

train_X,test_X,train_y,test_y=train_test_split(data,target,test_size=0.25,random_state=42)

# 模型训练
mlp_hw=MLPClassifier(solver='adam',hidden_layer_sizes=(64,32,32),activation='relu',max_iter=1000,alpha=1e-3,random_state=1)
mlp_hw.fit(train_X,train_y)
pre_x=mlp_hw.predict(train_X)

# 三维作图比较
fig=plt.figure()
ax=Axes3D(fig,rect=[0,0,1,1],elev=20,azim=20)
ax.scatter(train_X[:,0],train_X[:,1],train_X[:,2],marker='o',c=train_y)
plt.title("ture_label")
plt.show()

fig=plt.figure()
ax=Axes3D(fig,rect=[0,0,1,1],elev=20,azim=20)
ax.scatter(train_X[:,0],train_X[:,1],train_X[:,2],marker='o',c=pre_x)
plt.title('bp model')
plt.show()

# 准确率与混淆矩阵评估
print("accurancy:{:5f}".format(mlp_hw.score(test_X,test_y)))
pre_y=mlp_hw.predict(test_X)
print("ture label：\n",test_y)
print("pred label：\n",pre_y)
print(classification_report(test_y,pre_y))

con_mat=confusion_matrix(test_y,pre_y)
print(con_mat)

sns.set()
figure,ax=plt.subplots()
sns.heatmap(con_mat,cmap="YlGnBu_r",annot=True,ax=ax)
ax.set_title(u'confusion matrix')
ax.set_xlabel(u'predict')
ax.set_ylabel(u'true')
plt.show()
