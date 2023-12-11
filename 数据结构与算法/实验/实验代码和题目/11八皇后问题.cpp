#include<bits/stdc++.h>  
using namespace std;  
int a[100], b[100], c[100], d[100];//分别为行，列，左上到右下对角线，另一条对角线  
int n, total;  
bool flag = false;  
bool flag2 = false;  
  
void printres(){  
      
    if(flag2) cout<<endl;  
    for(int i=1; i<=n; i++){  
        for(int j=1; j<=n; j++){  
            flag2 = true;  
            if(j == a[i]) cout<<"Q";  
            else cout<<".";  
            if(j!=n) cout<<" ";  
        }  
        cout<<endl;  
    }  
    //cout<<a[k]<<" ";  
}  
  
void dfs(int i){        //i即为当前a（行）的位置  
    if(i>n){  
        flag = true;  
        printres();  
        return;  
    }  
    for(int j=1;j<=n;j++){  
        if((!b[j])&&(!c[i+j])&&(!d[i-j+n])){  
            a[i]=j;  
            b[j]=1;  
            c[i+j]=1;  
            d[i-j+n]=1;  
            dfs(i+1);  
            b[j]=0;  
            c[i+j]=0;  
            d[i-j+n]=0;  
        }  
    }  
}  
  
int main(){  
    cin>>n;  
    dfs(1);  
    if(!flag) cout<<"None"<<endl;  
    return 0;  
}  