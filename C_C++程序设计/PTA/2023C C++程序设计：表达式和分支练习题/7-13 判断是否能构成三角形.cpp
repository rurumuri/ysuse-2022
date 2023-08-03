#include<bits/stdc++.h>
using namespace std;


int main(){
	double a,b,c;
	cin>>a>>b>>c;
	if(a+b>c&&b+c>a&&c+a>b){
		double p = (a+b+c)/2;
		cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2);
		cout<<sqrt(p*(p-a)*(p-b)*(p-c));
	}else{
		cout<<"Error";
	}
}