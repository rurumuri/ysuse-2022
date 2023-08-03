#include<bits/stdc++.h>
using namespace std;

int func1(int a, int b){
	int res=min(abs(a),abs(b));
	while(abs(a)%res != 0 || abs(b)%res != 0)
		res--;
	return res;
}

int func2(int a,int b){
	int res=max(abs(a),abs(b));
	while(res%abs(a) != 0 || res%abs(b) != 0)
		res++;
	if(a<0 || b<0) res=-res;
	return res;
}
int main(){
	int a,b;
	while(cin>>a>>b)
		cout<<func1(a,b)<<" "<<func2(a,b)<<endl;
}