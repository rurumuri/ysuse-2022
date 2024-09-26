import numpy as np
import pandas as pd

dataset = pd.read_csv("data/data76088/3_buy.csv")
dataset.iloc[:, 0:]

# ID3
from sklearn import tree
from sklearn.metrics import accuracy_score
clf_A = tree.DecisionTreeClassifier(criterion="gini")
clf_A.fit(dataset.iloc[:7, :-1], dataset.iloc[:7, -1])
pred_A = clf_A.predict(np.array(dataset.iloc[7:, :-1]))
print('Accuracy:%s'% accuracy_score(dataset.iloc[7:, -1], pred_A))
clf_A

# CART
clf_B = tree.DecisionTreeClassifier(criterion="entropy")
clf_B.fit(dataset.iloc[:7, :-1], dataset.iloc[:7, -1])
pred_B = clf_B.predict(np.array(dataset.iloc[7:, :-1]))
print('Accuracy:%s'% accuracy_score(dataset.iloc[7:, -1], pred_B))
clf_B