//无向图存在欧拉回路的充要条件是：连通图、且所有结点的度均为偶数

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> vis;
vector<int> bfs_queue;
int n, m, tmp1, tmp2;

void graph_init(){
    cin>>n>>m;
    graph.resize(n+1, vector<int>(0));
    while(m--){
        cin>>tmp1>>tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }
}

void bfs_traverse(){
    vis.resize(n+1, false);
    bfs_queue.resize(n+1);
    bfs_queue.push_back(1);
    vis[1] = true;
    while(!bfs_queue.empty()){
        for(auto i : graph[bfs_queue.front()]){
            if(!vis[i]){
                vis[i] = true;
                bfs_queue.push_back(i);
            }
        }
        bfs_queue.erase(bfs_queue.begin());
    }
}

bool is_connect(){
    bfs_traverse();
    for(auto i = vis.begin()+1; i != vis.end(); i++){
        if(!*i) return false;
    }
    return true;
}

bool is_all_node_even_degree(){
    for(auto i = graph.begin()+1; i != graph.end(); i++){
//        cout<<(*i).size()<<endl;
//        for(auto j : *i) cout<<">"<<j<<" ";
//        cout<<endl;
        if((*i).size()%2 == 1) return false;
    }
    return true;
}

int main(){
    graph_init();

    if(is_connect() && is_all_node_even_degree()) cout<<1<<endl;
    else cout<<0<<endl;
}