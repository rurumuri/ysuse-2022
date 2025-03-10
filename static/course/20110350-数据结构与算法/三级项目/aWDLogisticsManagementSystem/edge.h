
// edge类：有向有权图的边的数据结构，模板参数T为边权存储的类型

#ifndef edge_
#define edge_

#include<iostream>

using namespace std;

template<class T>
class edge {
public:
    int vertex_in;
    int vertex_out;
    T w;

    // 构造函数，要求始点终点和边权三个参数
	edge(int vertex_in_id = -1, int vertex_out_id = -1, T weight = 0) { vertex_in = vertex_in_id; vertex_out = vertex_out_id; w = weight; }
	~edge() {}

    // 获取三项私有数据的方法
	int get_vertex_in_id() { return vertex_in; }
	int get_vertex_out_id() { return vertex_out; }
	T get_weight() { return w; }

    // 标准输出edge的信息
	void output() { cout << "(" << vertex_in << "," << vertex_out << "," << w << ")"; }
};

#endif