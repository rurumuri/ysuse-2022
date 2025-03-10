/*
最大公约数：辗转相减法
最小公倍数：乘积与最大公约数之商
*/
#include<bits/stdc++.h>
using namespace std;

int func1(int a, int b){
	int x=min(abs(a),abs(b)), y=max(abs(a),abs(b));
	while(y!=0){
		int tx=x,ty=y;
		x=min(tx,ty);
		y=max(tx,ty);
		y=y-x;
	}
	return x;
}

int main(){
	int a,b,r1,r2;
	while(cin>>a>>b){
		r1=func1(a,b);
		r2=abs(a*b/r1);
		if(a<0||b<0) r2=-r2;
		cout<<r1<<" "<<r2<<endl;
	}
}