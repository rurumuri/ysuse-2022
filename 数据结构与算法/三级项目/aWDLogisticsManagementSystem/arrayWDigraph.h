
// arrayWDigraph基础实现，包含添加或删除点、边、拓扑排序、最短路径、寻找联通集等功能，供上层应用开发
// 模板类函数具体实现拆分到其余tpp文件

#ifndef arrayWDigraph_
#define arrayWDigraph_

#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <queue>
#include <algorithm>
#include "graph.h"
#include "edge.h"
#include "node.h"
#include "vertexIterator.h"

template<class T>
class arrayWDigraph : public graph<T> {

protected:
    /// 图数据结构部分
    // 顶点及其联通关系的结构体（n_vertex，强调节点的联通关系，而非边的信息）
	struct Vertex {
		int node_id; // 节点编号
		vector<Node<T>> conn_vertices; // 节点联通的节点集合
	};
	int n_vertex;   // 顶点数
	int n_edge; // 边数
	vector<Vertex> G; // 存储图中的边（利用点和点之间的关系Vertex结构体存边,比如节点1的G[1].conn_vertices即存储了联通点，等效于节点1的出边）
	vector<NodeInfo> V; // 存储图中的点 // 注意GV中的点索引不同于节点的node_id，需要getIndex函数根据NodeInfo的node_id编号（人类可读）获取V<NodeInfo>中对应的索引（即对应到V的存储结构）

    /// 类方法可能使用到的公共变量
    const T INF = 9999999; // 用作infinite值
    //const T INF = std::numeric_limits<T>::max(); // 用作infinite值
	int* vis; // 是否访问，寻路算法共享
	int length; // 路径长度
	int** path_floyd; // 佛洛依德的路径
	T** dis_floyd; // 佛洛依德的距离

	// dijkstra专用变量
	bool* is_reachable; // 某点是否可达
	T* dis_dijkstra; // 到某点的最少费用
    int* path_dijkstra; // 储存路径
	stack<int> path_stack_dijkstra; // 储存路径，回溯输出


public:
    /// arrayWDigraph基础，包含基类函数、迭代器和实用子方法（实现于arrayWDigraph_basic.tpp）
    // 基类函数实现
    explicit arrayWDigraph(int n_vertex_primary);
	~arrayWDigraph(){};
    int numberOfVertices() const {return n_vertex;}; // 获取点的个数
    int numberOfEdges() const {return n_edge;}; // 获取边的个数
    bool existsEdge(int vertex_in_id, int vertex_out_id) const; // 判断是否存在边a->vertex_out_id
    void insertEdge(edge<T>* Edge); // 插入边
    bool eraseEdge(int v1, int v2); // 删除边
    int degree(int v) const {return indegree(v) + outdegree(v);}; // 获取度
    int indegree(int v) const {return V[v].in_degree;}; // 获取入度
    int outdegree(int v) const {return V[v].out_degree;}; // 获取出度
    bool directed()  const { return true; }; // 是否为有向图
    bool weighted()  const { return true; }; // 是否为有权图


    // 实用基础子函数和图算法
    int _indegree(int x) {return indegree(getIndex(x));} // 获取入度子方法
    int _outdegree(int x) {return outdegree(getIndex(x));} // 获取出度子方法
	int getIndex(int x); // 获取编号为x的点的索引
	bool existVertex(int node_id); // 判断是否已经存在点v
	bool isEdgeLegal(int v1, int v2); // 判断边v1->v2是否合法
	bool isVertexLegal(int node_id); // 判断点v是否合法
	bool isWeightLegal(T weight); // 判断权值是否合法
    void updateWeight(int vertex_in_id, int vertex_out_id, T new_weight); // 更新权值
    void addVertexSingle(int node_id, string node_info_name); // 增加点
    void addVertex(); // 添加多个点
    void addVertex(int x); // 添加单个点（重载函数）
    void deleteVertexSingle(int node_id); // 删除点
    void deleteVertex(); // 删除多个地点
    void addEdge(); // 添加路
    void deleteEdge(); // 删除路
    void connectedSets(); // 输出连通集
    void outputG(); // 输出当前图所有边
    void outputV(); // 输出当前图所有点
    void clearAllFiles(); // 重置文件存储的信息

	// 基类迭代器子类实现
	class myIterator : public vertexIterator<T> {
	public:
		myIterator(Vertex& thelist) { // 传入引用，减小开销
			newlist = thelist.conn_vertices;
			size = newlist.size() - 1; // 初始化
			cur = 0;
		};
		int next() { // 取出当前，指向后一个
			if (cur > size)return 0; // 终止
			int nextVertex = newlist[cur].node_id; // 取出权值和下标
			cur++;//游标后移
			return nextVertex;
		};
		int next(T& theWeight) {
			if (cur > size)return 0; // 终止
			int nextVertex = newlist[cur].node_id; // 取出下标
			theWeight = newlist[cur].node_weight; // 取出权值，存放到传入引用参数
			cur++; // 游标后移
			return nextVertex;
		};
		int next(T& theWeight, int& pos) {
			if (cur > size) return 0; // 终止
			int nextVertex = newlist[cur].node_id; // 取出下标
			theWeight = newlist[cur].node_weight; // 取出权值，存放到传入引用参数
			pos = cur++; // 游标后移
			return nextVertex;
		};
		void reset() { cur = 0; } // 重置游标
	protected:
		vector<Node<T>> newlist;
		int x;
		int cur;
		int size;
	};

	// 图迭代器成员实现
	myIterator* iterator(int node_id) {
		if (isVertexLegal(node_id)) {
			return new myIterator(G[getIndex(node_id)]); // 为类中传入边表，因为该类无法使用主类中的nodes
		}
	};


    /// DFS（实现于arrayWDigraph_dfs.tpp）
    void rDFS(int start, int label);// 被DFS调用
    void sDFS(int start, int label); //被dfs调用
	void customizedDFS(int start, int label);//自带的迭代器dfs
	void DFS(int start, int label);//课本的迭代器的DFS
    void DFSPerformCompare(); // dfs性能测试


    /// 文件操作（实现于arrayWDigraph_file_io.tpp）
    T stringToT(const string& str); // 将string转化为T，用于从文件读取时使用
	string getFirstPart(string s); // 返回第一部分的字符串
	string getSecondPart(string s); // 返回第二部分的字符串
	string getThirdPart(string s); // 返回第三部分的字符串
	int locateFirstBlank(string s); // 返回第一个空格位置的字符串索引
	int locateSecondBlank(string s); // 返回第二个空格位置的字符串索引
    void updateEdgeWeight(int x, int y, T z); // 在文件中更新权值
    void addVertexFile(int x, string y); // 在文件中写入点x
    void deleteVertexFile(int x); // 删除点的文件操作
    void addEdgeFile(int x, int y, T z); // 在文件中写入边x->y
    void deleteEdgeFile(int x, int y); // 删除路的文件操作


    /// 拓扑相关算法（实现于arrayWDigraph_topo.tpp）
    void _topologicalSorting(); // 拓扑排序
    void topoRank(); // 拓扑排序方法


    /// 路径相关图算法（实现于arrayWDigraph_path.tpp）
    void floydGetPath(); // 最短路径方法，floyd前端函数
    void _floydPrintPath(); // 打印最短路径，依据_floyd函数运行结果递归输出
    void _floyd_PrintPath(int i, int j); // 打印最短路径子方法
    void _floyd(); // 佛洛依德算法

    void dijkstraGetPath(); // 最短路径方法，dijkstra前端函数
    void _dijkstra(int start); // Dijkstra算法核心部分，计算了起始点到所有其他点的最短路径（单源）并保存到dis_dijkstra数组中
    T* _shortPathDijkstra(int start, int end); // 算法中间层，初始化必要数据，异常捕获，预处理路径细节数据等
    void _dijkstraResult(int start, int end); // 此函数仅取目标终点的最短路径并输出

    T _aStarHeuristic(int current, int goal); // 启发函数
    vector<int> _aStar(int start, int end); // 核心算法
    void AStarGetPath(); // A*寻路 前端函数

    void _shortPathVia(int start, int through, int end);
    void shortPathVia(); // 两点间且通过某点的最短路径


    /// 初始化相关函数（实现于arrayWDigraph_init.tpp）
    void clearProgramData(); // 清空图
    void autoInitFromFile1(); // 文件初始化1
    void autoInitFromFile2(); // 文件初始化2
    void init(); // 初始化
};


// 实现文件（.tpp）的包含
#include "arrayWDigraph_basic.tpp"
#include "arrayWDigraph_file_io.tpp"
#include "arrayWDigraph_init.tpp"
#include "arrayWDigraph_path.tpp"
#include "arrayWDigraph_dfs.tpp"
#include "arrayWDigraph_topo.tpp"


#endif
