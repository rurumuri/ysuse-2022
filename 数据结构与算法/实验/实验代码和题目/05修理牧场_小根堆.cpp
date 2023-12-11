#include <queue>
#include <iostream>
using namespace std;

priority_queue<int, vector<int>, greater<int>> woods; // 使用STL优先队列作为小根堆
int n, t, cost, cost_total;

void init(){
    cin>>n;
    while(n--){
        cin>>t;
        woods.push(t);
    }
}

void get_min_cost(){
    int tmp1, tmp2;

    //蕴含了构造哈夫曼树的思想
    while(woods.size()>1){
        tmp1 = woods.top(); woods.pop();
        tmp2 = woods.top(); woods.pop();
        cost = tmp1 + tmp2;
        cost_total += cost;
        woods.push(cost);
    }
};

int main(){
    init();
    get_min_cost();
    cout<<cost_total<<endl;
}