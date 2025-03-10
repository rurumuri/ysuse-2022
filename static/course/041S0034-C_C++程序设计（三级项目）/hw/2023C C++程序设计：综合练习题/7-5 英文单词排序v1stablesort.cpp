/*
注意看，这是stlsort的第三个参数！它本质上都是bool。具体的还不太懂

测试点3wa：“sort排序是不稳定的，不能保证如果长度相同，按照输入的顺序不变。”不理解，那么测试点0呢，
不是也有并列的？

（源于csdn：）sort是主要用到了快速排序（平均时间复杂度为O(nlogn)），还结合了插入排序（时间复杂度为O(n2)）
和堆排序（时间复杂度为O(nlogn)）

最终解决方案stable_sort，问题确实是对于相等元素可能换序！！！
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
	string stemp;
	vector<string> s;
	
	while(true){
		cin>>stemp;
		if(stemp=="#") break;
		s.push_back(stemp);
	}
	
	stable_sort(s.begin(), s.end(), [](string a, string b){	//lambda表达式简化，也可单独函数而后传入“函数”
		return a.length() < b.length();
	});
	
	for(vector<string>::iterator it=s.begin(); it!=s.end(); it++){
		cout<<*it<<" ";
	}
}