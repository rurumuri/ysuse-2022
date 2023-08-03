#include<bits/stdc++.h>
using namespace std;


int main(){
	int c;
	stack<int> s;
	while(true){
		while((c=getchar())!='\n'&&c!=EOF) s.push(c-'0');
		while(!s.top()) s.pop();	//丢弃开头的0
		while(s.size()) cout<<s.top(), s.pop();
		cout<<'\n';
	}
}