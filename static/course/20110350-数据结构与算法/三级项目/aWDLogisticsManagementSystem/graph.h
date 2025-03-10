
// graph抽象基类

#ifndef graph_
#define graph_

#include"edge.h"
#include"vertexIterator.h"

template<class T>
class graph{
public:
    virtual ~graph() {}
    virtual int numberOfVertices() const = 0;//点的个数
    virtual int numberOfEdges() const = 0;//边的个数
    virtual bool existsEdge(int, int) const = 0;//判断是否存在从前面点到后面点的边
    virtual void insertEdge(edge<T>*) = 0;//插入边
    virtual bool eraseEdge(int, int) = 0;//删除边
    virtual int degree(int) const = 0;//度
    virtual int indegree(int) const = 0;//入度
    virtual int outdegree(int) const = 0;//出度
    virtual bool directed() const = 0;//方向
    virtual bool weighted() const = 0;//权重
    virtual vertexIterator<T>* iterator(int) = 0;//迭代器
};

#endif
