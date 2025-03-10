// 使用分治思想，结合快速排序的思路

#include <iostream>
#include <vector>
using namespace std;

int n, k, tmp;
vector<int> arr;

void init(){
    cin>>n>>k;
    while(n--){
        cin>>tmp;
        arr.push_back(tmp);
    }
}

// 借用快速排序思想，返回一轮排序后枢轴位置（vector迭代器）（从小到大顺序）
vector<int>::iterator quick_search(vector<int>& arr, vector<int>::iterator left, vector<int>::iterator right){
    auto l = left, r = right;
    while(l < r){
//        for(auto i : arr) cout<<" "<<i;
//        cout<<endl;
        while(l < r && *r >= *left) r--;
        while(l < r && *l <= *left) l++; // 必然移动一次，不用担心参考被移走
        if(l < r) swap(*l, *r);
    }
    swap(*left, *l);
//    for(auto i : arr) cout<<" "<<i;
//    cout<<endl;
    return l;
}

vector<int>::iterator get_k_th_element(vector<int>& arr, vector<int>::iterator left, vector<int>::iterator right, int k){
    auto cur_pos = quick_search(arr, left, right);
    while(cur_pos + k != arr.end()){
        // 找到的元素比目标小，在右侧继续找
        if((arr.end() - cur_pos > k)){
            left = cur_pos + 1;
            cur_pos = quick_search(arr, left, right);
        }
        // 找到的元素比目标大，在左侧继续找
        if((arr.end() - cur_pos < k)){
            right = cur_pos - 1;
            cur_pos = quick_search(arr, left, right);
        }
    }
    return cur_pos;
}

int main(){
    init();
    cout<<*get_k_th_element(arr, arr.begin(), arr.end()-1, k);
}