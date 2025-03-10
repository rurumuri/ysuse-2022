/*偷懒可耻！！！*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
	int n,t;
	vector<int> rank;
	cin>>n;
	for(int i=0;i<n+1;i++){//注意貌似不能直接cin>>vector[x]
		cin>>t;
		rank.push_back(t);
	}
	stable_sort(rank.begin(), rank.end());
	for(int i=0;i<n+1;i++)
		cout<<rank[i]<<" ";
}