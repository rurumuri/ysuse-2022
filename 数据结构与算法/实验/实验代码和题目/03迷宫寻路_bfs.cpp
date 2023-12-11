#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// node结构体 用来存储bfs过程中的坐标信息，包括xy坐标、遍历id和父节点id
struct node{
    int x = 0;
    int y = 0;
    int nid = 0;
    int last = 0;
};

vector<vector<int>> graph;
vector<vector<bool>> vis;
vector<node> bfs_queue;
stack<node> route;

int tm, tn, tmp;
int nav[4][2] = {{0, 1},
                 {1, 0},
                 {0, -1},
                 {-1, 0}};

// 初始化graph和vis
void graph_init(int m, int n){
    graph.resize(0);
    graph.resize(m+1, vector<int>(n+1, 0));
    vis.resize(0);
    vis.resize(m+1, vector<bool>(n+1, false));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin>>tmp;
            if(tmp) graph[i][j]=1;
        }
    }
}

// 回溯最短路径
void trace_back(){
    // test
//    for(auto i : bfs_queue){
//        cout<<i.x<<" "<<i.y<<" "<<i.nid<<" "<<i.last<<endl;
//    }

    node i = bfs_queue.back();
    while(true){
        route.push(i);
        if(i.last == -1) break;
        i = bfs_queue[i.last];
    }

    while(!route.empty()){
        cout<<route.top().x<<","<<route.top().y<<endl;
        route.pop();
    }

    cout<<endl;
}

// bfs搜索路径
void graph_bfs(int m, int n){
    bfs_queue.reserve(m*n+1);
    bfs_queue.resize(0);
    bfs_queue.push_back(node{1, 1, 0, -1});
    vis[1][1] = true;
    auto head = bfs_queue.begin();
    while(head != bfs_queue.end()){
        //cout<<head->nid<<endl;
        //cout<<head->x<<" "<<head->y<<endl; // test
//        if(head->x == m && head->y == n){
//            //cout<<"yes!!!"<<endl; // test
//            trace_back();
//            return;
//        }
        for(const auto& i : nav ){
            int xnext = head->x+i[0], ynext = head->y+i[1];
            //cout<<"> "<<xnext<<" "<<ynext<<endl; // test
            if(xnext < 1 || xnext > m || ynext < 1 || ynext > n)
                continue;
            if(graph[xnext][ynext] == 1 || vis[xnext][ynext])
                continue;
            //cout<<">> "<<bfs_queue.back().nid+1<<" "<< head->nid<<endl; // test
            bfs_queue.push_back(node{xnext, ynext, bfs_queue.back().nid+1, head->nid});
            vis[xnext][ynext] = true;

            if(xnext == m && ynext == n){
                trace_back();
                return;
            }
        }
        head++;
    }
    cout<<"NO FOUND"<<endl;
}

int main(){
    while(true){
        cin>>tm>>tn;
        if(tm==-1 && tn==-1) return 0;
        graph_init(tm, tn);
        graph_bfs(tm, tn);
    }
}


// #include<bits/stdc++.h>
// using namespace std;
// int m, step[4][2] = { {1,0} , {0,1} , {-1,0} , {0,-1} };


// struct site{
// 	int x, y, k;
// 	friend bool operator<(const struct site& a, const struct site& b) {
//         if (a.x < b.x || (a.x == b.x && a.y < b.y)) return true;
//         return false;
//     }
// }p[100];

// int main(){
// 	cin>>m;
// 	while(m != -1) {
// 		map<site,site> f;
//         queue<site> q;
//         struct site temp;
// 		int n,a[100][100],flag = 1;
// 		cin>>n;

// 		for(int i = 1; i <= m; i++)
// 			for (int j = 1; j <= n; j++)
// 				cin>>a[i][j];

// 		for(int i = 1; i <= m; i++) {
// 			a[i][0] = 1;
// 			a[i][n+1] = 1;
// 		}

// 		for (int j = 1; j <= n; j++){
// 			a[0][j] = 1;
// 			a[m+1][j] = 1;
// 		}

// 		temp.x = 1; temp.y = 1;
// 		q.push(temp);
// 		a[1][1] = 6;
// 		while(!q.empty()){
// 			temp = q.front(); q.pop();
// 			int x = temp.x, y = temp.y;
// 			if(x == m && y == n) {
// 				flag = 0; int k = 0; p[k++] = temp;
// 				while(temp.x != 1 || temp.y != 1){
// 					p[k++] = f[temp];
// 					temp = f[temp];
// 				}
// 				for(int i = k-1; i >= 0; i--)
// 					cout<<p[i].x<<','<<p[i].y<<endl;
// 				break;
// 			}
// 			for (int w = 0; w < 4; w++) {
// 				temp.x = x + step[w][0];
// 				temp.y = y + step[w][1];
// 				if(a[temp.x][temp.y] == 0){
// 					q.push(temp);
// 					a[temp.x][temp.y] = 6;
// 					f[temp].x = x;
// 					f[temp].y = y;
// 				}
// 			}
// 		}

// 		if(flag) cout<<"NO FOUND";
// 		cout<<endl; cin>>m;
// 	}
// 	return 0;
// }