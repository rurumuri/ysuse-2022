#include<iostream>
#include<cmath>
using namespace std;
int n, cn, col;
string s;
char ss[1001][1001];


int main(){
	cin>>n;
	getchar(); getline(cin,s);
	cn=s.length(); col=ceil(cn/(double)n);

	for(int i=1;i<=col;i++)
		for(int j=1;j<=n;j++){
			if((i-1)*n+j-1<cn) ss[i][j]=s[(i-1)*n+j-1];
			else ss[i][j]=' ';
		}
			
	for(int i=1;i<=n;i++){
		for(int j=col;j>=1;j--){
			cout<<ss[j][i];
		}
		cout<<endl;
	}
}