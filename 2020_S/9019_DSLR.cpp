#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n;

class node{
public:
    int value;
    string task;
    node** children;
};

queue<node*> globalQ;

string make(node* cur){
    cur->children = new node*[4];
    node* D = new node();
    D->value = (2*cur->value)%10000;
    D->task = cur->task+"D";
    cur->children[0]=D;
    globalQ.push(D);

    node* S =new node();
    S->value = cur->value-1;
    S->task = cur->task+"S";
    cur->children[1]=S;
    globalQ.push(S);

    node* L = new node();
    int temp =10*cur->value;
    temp = temp + temp/10000;
    temp = temp%10000;
    L->value = temp;
    L->task = cur->task+"L";
    cur->children[2]=L;
    globalQ.push(L);

    node* R = new node();
    temp = cur->value%10;
    temp = temp*1000+cur->value/10;

    R->value = temp;
    R->task = cur->task+"R";
    cur->children[3]=R;
    globalQ.push(R);

    return "NO";
}

int main(){
    cin>>n;
    while(n>0){
        n--;
        int A,B;
        cin>>A>>B;
        node* Cur = new node();
        Cur->value = A;
        Cur->task="";

    }

    return 0;
}