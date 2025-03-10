#include<bits/stdc++.h>
#include<vector>
using namespace std;


//判断素数 优化 记忆化搜索
bool prime[114514];
int isprimerec[114514];
bool isPrime(int x){
	if(x==1 || x==4)
		return false;
	else if(x==2 || x==3 || x==5)
		return true;
	else if(isprimerec[x]==1)	//读取先前的记录
		return prime[x];
	else{
		isprimerec[x]=1;
		prime[x]=true;
		for(int i=2;i<=sqrt(x);i++){//平方根优化	
			if(x%i==0){
				prime[x]=false;
				break;
			}
		}	
	}
	return prime[x];
}

//读取一个偶数，判断对的数量
int solve(int n){
	int cnt = 0;	//计数
	for(int i=2;i<=n/2;i++){	//把这个数分成两份，到中间就停，防止出现形如(2,3)和(3,2)重复
		if(isPrime(i)&&isPrime(n-i))	//判断两者均为素数
		cnt++;
	}
	return cnt;
}

int main(){
	int n;
	while(cin>>n){	//读入
		if(n==0) break;	//终止
		cout<<solve(n)<<endl;
	}
}