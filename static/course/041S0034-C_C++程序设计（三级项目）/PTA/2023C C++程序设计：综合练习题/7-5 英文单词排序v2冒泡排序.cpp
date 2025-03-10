/*
*/
#include<bits/stdc++.h>
using namespace std;

struct str{
	string s;
	int len;
};
typedef struct str sstr;

void swaps(sstr &l, sstr &r){
	sstr t = l;
	l = r;
	r = t;
}

int main(){
	sstr ori[21];//注意，即使最大值20，它有一个#，所以要21，否则#3wa段错误
	int n=0;
	while(true){
		cin>>ori[n].s;
		ori[n].len=ori[n].s.length();
		if(ori[n].s=="#")
			break;
		n++;
	}
	
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(ori[i].len>ori[j].len)
				swap(ori[i], ori[j]);
	
	for(int i=0;i<n;i++)
		cout<<ori[i].s<<" ";
}