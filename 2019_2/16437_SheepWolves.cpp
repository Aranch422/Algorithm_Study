#include <iostream>
#include <vector>

using namespace std;

int N;
struct Node{
    char animal;
    long long int num;
    int parent;
    vector<int> child;
};

Node Ani[123457];

void init(){
    cin>>N;
    for(int i=2;i<=N;i++){
        cin>>Ani[i].animal;
        cin>>Ani[i].num;
        cin>>Ani[i].parent;
        Ani[Ani[i].parent].child.push_back(i);
    }

}

int ret=0;

void postT(Node n){
    Node temp=n;
    //밑으로 내려가기
    while(!temp.child.empty()){
        temp=Ani[temp.child.front()];
    }
    ret+=temp.num;
    if(ret<=0) ret=0;

}

int main(){

    return 0;
}


