import pandas as pd
import numpy as np
from sklearn import metrics
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

# 读取数据
df = pd.read_csv('data/data76878/4_beverage.csv')
print(df)

# 绘图观察
df=np.array(df)
plt.scatter(df[:, 0], df[:, 1],color='m', marker='o')
plt.xlabel('juice')
plt.ylabel('sweety')
plt.show()

# 建模与评测
score_all=[]
for i in range(2,7):

    est = KMeans(n_clusters=i)
    est.fit(df)
    y_pred = est.fit_predict(df)

    plt.scatter(df[:, 0], df[:, 1], c=y_pred,label=i)
    plt.legend(loc=2)
    plt.xlabel('juice')
    plt.ylabel('sweet')

    center = est.cluster_centers_
    print("k=%d:" % i)
    print(est.labels_)
    print(center)
    plt.scatter(
        center[:, 0],
        center[:, 1],
        marker="x",
        c="black",
        s=48
    )


    score = metrics.calinski_harabasz_score(df, y_pred)
    score_all.append(score)
    print("score=",score)
    print('\n')
    plt.show()