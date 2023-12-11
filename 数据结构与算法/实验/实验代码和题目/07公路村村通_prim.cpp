#include<iostream>
#include<vector>
#define INF 123456789 // 0x3f3f3f3f不好使
using namespace std;

vector<vector<int>> graph; // 邻接数组存储
int n, e;
int tmp1, tmp2, tmp3;

// 初始化
void graph_init(){
    cin>>n>>e;
    graph.resize(n+1, vector<int>(n+1, INF)); // 初始化为INF，代表不联通

    for(int i=1; i<=e; i++){
        cin>>tmp1>>tmp2>>tmp3;
        graph[tmp1][tmp2] = tmp3;
        graph[tmp2][tmp1] = tmp3;
    }
}

// prim算法计算最小生成树的值，值为INF说明图不联通，输出-1，否则输出权值和
void prim(){
    vector<int> low_cost; // 记录每个节点连接到目前的生成树（即目前已经处理过的所有点）的最小权值
    vector<int> vis; // 标识该点是否处理过
    low_cost.resize(n+1, INF);
    vis.resize(n+1, false);


    int curMin = INF, curId = 1, sum = 0; // 默认从1号开始遍历
    //vis[1] = true; low_cost[1] = 0;
    // 处理每个点，但不一定是按顺序
    for(int i=2; i<=n; i++){
        //cout<<curId<<endl;
        vis[curId] = true, low_cost[curId] = 0;

        // 用这个点的边信息来更新low_cost（这也是很像Dijkstra算法的地方）
        for(int j=1; j<=n; j++){
            if(graph[curId][j]<low_cost[j] && !vis[j]){
                low_cost[j] = graph[curId][j];
            }
        }

        curMin = INF;
        //int tmp_curId = curId;
        // 求当前点出边的最小权值（并且边不能通往一个已经处理的点）
        for(int j=1; j<=n; j++){
            if(low_cost[j]<curMin && !vis[j]){
                curMin = low_cost[j];
                curId = j; // 保存，供下个循环处理
            }
        }

        //if(tmp_curId == curId) for(int j=1; j<=n; j++) if(!vis[j]) break;

        //cout<<curId<<" "<<curMin<<endl;
        // 将权值计入总和
        sum += curMin;
    }
    if(sum > INF) cout<<"-1"<<endl;
    else cout<<sum<<endl;
}

int main(){
    graph_init();
    prim();
}