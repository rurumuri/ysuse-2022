#include<bits/stdc++.h>
using namespace std;
vector<int> ints;
int n=3;

int main(){
	while(n--){int t; cin>>t; ints.push_back(t);}
	cout<<*max_element(ints.begin(), ints.end());
}