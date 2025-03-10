#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n1,n2,arr1[21],arr2[21];
vector<int> rec;

int main(){
	cin>>n1; for(int i=1;i<=n1;i++) cin>>arr1[i];
	cin>>n2; for(int i=1;i<=n2;i++) cin>>arr2[i];
	
	for(int i=1;i<=n1;i++)
		if(find(arr2+1, arr2+n2+1, arr1[i])==arr2+n2+1)
			if(find(rec.begin(),rec.end(),arr1[i])==rec.end())
				rec.push_back(arr1[i]);
	for(int i=1;i<=n2;i++)
		if(find(arr1+1, arr1+n1+1, arr2[i])==arr1+n1+1)
			if(find(rec.begin(),rec.end(),arr2[i])==rec.end())
				rec.push_back(arr2[i]);
	for(auto i = rec.begin(); i!=rec.end(); i++){
		cout<<*i;
		if(i!=rec.end()-1) cout<<" ";
	}
}