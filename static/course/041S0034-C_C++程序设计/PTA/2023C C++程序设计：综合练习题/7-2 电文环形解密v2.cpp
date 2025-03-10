#include<bits/stdc++.h>
using namespace std;


int main(){
	int x;
	string s;
	cin>>x;
	getchar();	//把回车处理掉
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(s[i]>='a'&&s[i]<='z'){
			s[i]='a'+(s[i]-'a'-x%26+26)%26;
		}
		else if(s[i]>='A'&&s[i]<='Z'){
			s[i]='A'+(s[i]-'A'-x%26+26)%26;
		}
	}
	cout<<s;
}