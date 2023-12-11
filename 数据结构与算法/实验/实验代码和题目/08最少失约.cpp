// 使用贪心算法
// 另外注意测试数据可能无序

#include <iostream>
#include <map>
using namespace std;

int T, n;
multimap<int, int> events; // 之前用的是map，然而map不允许出现重复键。评价为不了解容器性质乱用导致的。


int solve_problem(){
    events.clear();
    int cnt = 0, tmp1, tmp2;

    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>tmp1>>tmp2;
        events.insert({tmp2, tmp1}); // 让map按结束时间从早到晚顺序排列
    }

    tmp1 = -1;
    for(auto i : events){
        //cout<<i.second<<" "<<i.first<<endl; // test
        if(i.second >= tmp1){
            //cout<<">"<<i.second<<" "<<i.first<<endl; // test
            cnt++;
            tmp1 = i.first;
        }
    }

    return n - cnt;
}

int main(){
    cin>>T;
    while(T--){
        cout<<solve_problem()<<endl;
    }
}