// 为什么呢 QAQ
// 因为排序把最后一个忘排了QAQ
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct obj{
    int w = 0;
    int v = 0;
    double vpw = 0;
};
int n, c, total = 0;
int w, v;
vector<obj> objs;

int potential_v(int cur_n, int cur_total_c){
    int res = 0;
    for(int i=cur_n; i<=n; i++){
        if(cur_total_c - objs[i].w >= 0){
            res += objs[i].v;
            cur_total_c -= objs[i].w;
        }
        else{
            res += objs[i].vpw * cur_total_c; // 按vpw排的，后面即使能加整个的也比不上这个加部分的，何况这个也加不上，是最大的
            cur_total_c = 0;
            break;
        }
    }
    return res;
}

void dfs(int obj_id, int cur_total_v, int cur_total_c){
    if (obj_id > n){
        total = max(total, cur_total_v);
        return;
    }
    if(cur_total_c - objs[obj_id].w >= 0)
        dfs(obj_id + 1, cur_total_v + objs[obj_id].v, cur_total_c - objs[obj_id].w);// 拿
    if(potential_v(obj_id, cur_total_c)+cur_total_v>=total) { // 嘻嘻 为什么呢
        //cout<<potential_v(obj_id, cur_total_c)+cur_total_v<<"|"<<total<<endl;
        dfs(obj_id + 1, cur_total_v, cur_total_c); //不拿这个 // 看清拿哪个 不拿哪个
    }
    return;
}

int main(){
    cin>>n>>c;
    objs.resize(101);
    for(int i = 1; i<=n; i++){
        cin>>w>>v;
        objs[i] = obj{w, v, 1.0*v/w};
    }
    //for(auto i : objs) cout<<i.vpw<<" "; cout<<endl;
    //sort(objs.begin()+1, objs.begin()+n, [](obj& a, obj& b){ //唉你真的是
    sort(objs.begin()+1, objs.begin()+n+1, [](obj& a, obj& b){ // 唉唉
        return a.vpw > b.vpw;
    });
    //for(auto i : objs) cout<<i.vpw<<" "; cout<<endl;
    dfs(1, 0, c);
    cout<<total;
}