//草草草忘看题了可能是负数
#include<iostream>
#include<iomanip>
using namespace std;
int h,m,dh,dm,t1,t2;


int main(){
	cin>>t1>>t2;
	m=t1%100, h=t1/100;
	dm=t2%60, dh=t2/60;
//	cout<<m<<" "<<h<<" "<<dm<<" "<<dh;

	m+=dm, h+=dh;
	h+=m/60, m%=60;
	while(m<0){
		m+=60, h-=1;	//加这一句就行，不换天，简单不少
	}
	
	cout<<h<<setw(2)<<setfill('0')<<m;
}