#include<iostream>
using namespace std;


double fact(int n){
	double res = 1;
	while(n>0)
		res *= n--;
	return res;
}
int main(){
	int m, n;
	cin>>m>>n;
	cout<<"result = "<<fact(n) / (fact(m) * fact(n - m))<<endl;
}