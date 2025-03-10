#include <iostream>
#include <stack>

using namespace std;

int n, t, op1, op2;
char c, op;
stack<int> S1;
stack<char> S2;

void init(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>t;
        S1.push(t);
    }
    for(int i=1; i<=n-1; i++){
        cin>>c;
        S2.push(c);
    }
}


int execute(){
    op1 = S1.top(); S1.pop();
    op2 = S1.top(); S1.pop();
    op = S2.top(); S2.pop();

    switch (op) {
        case '+':
            S1.push(op2 + op1);
            break;
        case '-':
            S1.push(op2 - op1);
            break;
        case '*':
            S1.push(op2 * op1);
            break;
        case '/':
            if (op1 == 0) {
                cout << "ERROR: " << op2 << "/0";
                return -1;
            }
            else S1.push(op2 / op1);
            break;
    }
    return 0;
}


int main(){
    init();
    while(!S2.empty()){
        if(execute()) return 0;
    }
    cout<<S1.top()<<endl;
}