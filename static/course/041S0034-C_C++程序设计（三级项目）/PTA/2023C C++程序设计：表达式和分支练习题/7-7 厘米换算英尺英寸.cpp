#include<iostream>
using namespace std;


int main(){
	double cm,foot,inch;
	cin>>cm;
	foot=(int)(cm/30.48);
	inch=(int)((cm/30.48-foot)*12);
	cout<<foot<<" "<<inch;
}