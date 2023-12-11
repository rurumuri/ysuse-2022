#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> tower;
int n, T;


void init(){
    cin >> n;
    tower.clear();
    tower.resize(n, vector<int>(0));

    // 读取数塔
    for (int i = 0; i < n; ++i){
        tower[i].resize(i+1);
        for (int j = 0; j <= i; ++j){
            cin >> tower[i][j];
        }
    }
}

// 动态规划求解
int dp(){
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                tower[i][j] += tower[i - 1][j];  // 只能从上一层的第一个结点到达
            } else if (j == i) {
                tower[i][j] += tower[i - 1][j - 1];  // 只能从上一层的最后一个结点到达
            } else {
                tower[i][j] += max(tower[i - 1][j], tower[i - 1][j - 1]);  // 选择上一层两个相邻结点中较大的那个
            }
        }
    }

    return *max_element(tower[n - 1].begin(), tower[n - 1].end());
}



int main() {
    cin >> T;
    while (T--) {
        init();
        cout << dp() << endl;
    }
    return 0;
}
