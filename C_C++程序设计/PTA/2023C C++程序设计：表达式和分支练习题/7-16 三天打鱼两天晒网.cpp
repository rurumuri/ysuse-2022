#include <iostream>
using namespace std;


int main(){
	int n;
	cin>>n;
	int d = n % 5;
	if(d==1||d==2||d==3){
		cout<<"Fishing in day "<<n<<endl;
	}else{
		cout<<"Drying in day "<<n<<endl;
	}
}