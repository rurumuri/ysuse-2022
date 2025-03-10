#include<bits/stdc++.h>
#include<vector>
using namespace std;

//判断素数
bool isPrime(int x){
	if(x==1) return false;
	bool res = true;
	for(int i=2;i<=sqrt(x);i++)//平方根优化
		if(x%i==0)
			res=false;
	return res;
}

int solve(int n){
	int cnt = 0;
	for(int i=2;i<=ceil(n/2.0);i++){
		if(isPrime(i)&&isPrime(n-i))
		cnt++;
	}
	return cnt;
}

int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		cout<<solve(n)<<endl;
	}
}