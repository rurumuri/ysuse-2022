
// 节点node类和节点信息类

#ifndef node_
#define node_

#include<iostream>
#include <utility>
using namespace std;

template<class T>
class Node {
public:
    int node_id; // 该点的编号
    T node_weight; // 权值，作为连接到此点的边权值

	Node(int num, int we=0) {
        node_id = num;
        node_weight = we;
	}

	int getn() {return node_id;}
	int getw() {return node_weight;}

    // 重载==运算符（即比较规则，编号相同的节点即为同一节点）
	bool operator==(int y) {
		if (y == this->node_id) return true;
		else return false;
	}
};



// 节点信息类
class NodeInfo {
public:
    int node_id; // 节点编号
	int in_degree; // 该点的入度
	int out_degree; // 该点的出度
	string name; // 该点所代表的地区的名字

	NodeInfo(int nodeinfo_id = 0, string nodeinfo_name = "", int nodeinfo_in_degree = 0, int nodeinfo_out_degree = 0 ){
        name = std::move(nodeinfo_name); // 使用移动语义优化
        node_id = nodeinfo_id;
        in_degree = nodeinfo_in_degree;
        out_degree = nodeinfo_out_degree;
	}
};

#endif