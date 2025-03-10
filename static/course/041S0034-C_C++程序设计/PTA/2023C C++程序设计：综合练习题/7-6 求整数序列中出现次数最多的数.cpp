/*注意传参引用！*/
/*总感觉做的磨叽qwq*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct nnum{
	int num;
	int count=1;
};
typedef struct nnum nn;

nn* findnum(int n, vector<nn> &nnv){//注意：传入向量必须为引用，不然后续count计数会加到临时变量导致所有数字的count=1！！！
	nn* res=nullptr;
	for(int i=0;i<nnv.size();i++){
		if(n==nnv[i].num)
			res=&nnv[i];
	}
	return res;
}

int main(){
	int n,ntemp,maxnum,maxcount=0;
	cin>>n;
	
	vector<nn> ori;
	for(int i=1;i<=n;i++){
		cin>>ntemp;
		if(findnum(ntemp, ori)==nullptr){
			nn t;
			t.num=ntemp;
			ori.push_back(t);
		}
		else
			findnum(ntemp, ori)->count++;
	}
	
//test
//	for(int i=0;i<ori.size();i++){
//		cout<<ori[i].num<<" "<<ori[i].count<<" "<<endl;
//	}

	for(int i=0;i<ori.size();i++){
		if(maxcount<ori[i].count){
			maxnum=ori[i].num;
			maxcount=ori[i].count;
		}
	}
	
	cout<<maxnum<<" "<<maxcount;
} 