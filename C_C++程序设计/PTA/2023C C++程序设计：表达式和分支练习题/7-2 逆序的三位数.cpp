#include<iostream>
#include<string>
using namespace std;


int main(){
	string s;
	while(true){
		cin>>s;
		cout<<(s[2]-'0')*100+(s[1]-'0')*10+s[0]-'0'<<endl;
	}
}