#include <iostream>

using namespace std;

bool num[10001];

void init(){
    for(int i=0;i<10001;i++){
        num[i]=false;
    }
}

int selfcheck(int i){
    int ret=i;
    while(i>0){
       ret+=i%10;
       i=i/10;
    }
    return ret;
}

int main(){
    init();
    for(int i=1;i<=10000;i++){
        num[selfcheck(i)]=true;
    }

    for(int i=1;i<10001;i++){
        if(!num[i]) cout<<i<<"\n";
    }
    return 0;
}