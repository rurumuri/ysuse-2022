#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
//	cout<<(a^b^c);
	if(a^b==0) cout<<"C";
	else if(a^c==0) cout<<"B";
	else cout<<"A";
}