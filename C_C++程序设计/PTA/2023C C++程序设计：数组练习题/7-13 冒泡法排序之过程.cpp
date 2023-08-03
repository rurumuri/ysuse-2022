#include<iostream>
using namespace std;
int n, arr[11];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	if(n==1){
		cout<<arr[1];
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++)
			if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
		for(int j=1;j<=n;j++){
			cout<<arr[j];
			if(j!=n) cout<<" ";
		}
		cout<<endl;
	}
}