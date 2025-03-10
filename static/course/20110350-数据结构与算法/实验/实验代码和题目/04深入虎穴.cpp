
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> maze;
vector<bool> vis;
vector<int> depth; // 记录节点深度
int n, tmp1, tmp2, root_id;

void maze_init(int n){
    maze.resize(n+1, vector<int>(0));
    vis.resize(n+1, false); // 这里用来寻找入口节点
    depth.resize(n+1, -1); // 深度默认为-1，这样begin空位永远最小，无需担心max_element找0，0这样的问题，从而解决仅1个节点的问题

    // 读取
    for(auto i = maze.begin()+1; i != maze.end(); i++){
        cin>>tmp1;
        while(tmp1--){
            cin>>tmp2;
            (*i).push_back(tmp2);
            vis[tmp2] = true;
        }
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]) root_id = i;
    }

    vis.clear();
    vis.resize(n+1, false);
}

void dfs_traverse_maze(int current_id, int current_depth){
    depth[current_id] = current_depth;
    for(auto i : maze[current_id]){
        dfs_traverse_maze(i, current_depth+1);
    }
}

int main(){
    cin>>n;
    maze_init(n);
    dfs_traverse_maze(root_id, 0);
    cout<<max_element(depth.begin(), depth.end()) - depth.begin()<<endl;
}

