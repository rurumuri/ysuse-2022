#include <iostream>
using namespace std;

// 链表节点元素
struct Node{
    int data; // 数据元素
    Node* next = nullptr; // 指向下个节点
};

Node* init(int n){
    Node *head = nullptr, *p = nullptr; // head保存链表头节点供访问；p在链表创建的过程中承担中间值的作用

    while(n--){
        Node *q = new Node; // q 临时节点
        int t;
        cin>>t;
        q->data = t;
        if(head == nullptr) head = q; // head 为空则初始化head，保存头节点
        else p->next = q; // 否则（此时一定已经是第二次循环了，p必不为空），让上一个节点（p）的下一个（next）是这个（q）
        p = q; // 过渡，等效于p=p->next
    }
    return head;
}

// 遍历输出链表元素的函数
void traverse_output(Node* chain_begin){
    Node* p = chain_begin;
    while(p != nullptr){
        if(p != chain_begin) cout<<" ";
        cout << p->data;
        p = p->next;
    }
}

int main(){
    int n;
    cin >> n;
    Node* chain = init(n);
    traverse_output(chain);
}
