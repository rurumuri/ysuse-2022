#include <bits/stdc++.h>
using namespace std;

int main(){
	string a,s,b;
	cin>>a>>s>>b;
	int x=stoi(a),y=stoi(b);
	if(s[0]=='+') cout<<x+y;
	else if(s[0]=='-') cout<<x-y;
	else if(s[0]=='*') cout<<x*y;
	else if(s[0]=='/') cout<<x/y;
	else if(s[0]=='%') cout<<x%y;
	else cout<<"ERROR";
}