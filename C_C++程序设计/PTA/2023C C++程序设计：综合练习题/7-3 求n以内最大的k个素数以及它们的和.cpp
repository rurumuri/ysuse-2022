/*最后一个测试点TLE*/
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

int main(){
	int res=0,n,k,primecount=0;
	cin>>n>>k;
	vector<int> resprime(k,0);//向量存储，数组也一样（练手，但无效
	for(int i=n;i>1;i--){
		if(isPrime(i)&&primecount<k){
			res+=i;
			resprime[primecount]=i;
			primecount++;
		}
		if(primecount>=k)//偷懒，够了就跑	ε=ε=ε=(~￣▽￣)~
			break;
	}
	
	//按要求输出
	for(int i=0;i<primecount;i++){
		cout<<resprime[i];
		if(primecount!=1&&i!=primecount-1)
			cout<<"+";
		if(i==primecount-1)
			cout<<"=";
	}
	cout<<res;
}