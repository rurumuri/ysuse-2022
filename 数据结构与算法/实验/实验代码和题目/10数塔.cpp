// 分治思想，从下层向上层进行，计算每个节点的最大价值，最后计算到顶部即为结果

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tower;
int t, n, tmp;

void init(){
    cin>>n;
    tower.clear();
    tower.resize(n, vector<int>(0));
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cin>>tmp;
            tower[i].push_back(tmp);
        }
    }
}

void calculate(){
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            tower[i][j] += max(tower[i+1][j], tower[i+1][j+1]);
        }
    }
}

int main(){
    cin>>t;
    while(t--){
        init();
        calculate();
        cout<<tower[0][0]<<endl;
    }
}