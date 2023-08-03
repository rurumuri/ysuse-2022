#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main(){
	double a,b,c;
	cin>>a>>b>>c;
	if(a+b>c&&b+c>a&&a+c>b){
		double p = (a+b+c)/2;
		cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2);
		cout<<"area = "<<sqrt(p*(p-a)*(p-b)*(p-c))<<"; perimeter = "<<a+b+c;
	}
	else cout<<"These sides do not correspond to a valid triangle";
}