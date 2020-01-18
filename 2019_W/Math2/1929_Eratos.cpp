#include <iostream>
#include <math.h>

using namespace std;

int M,N;
bool num[1000001];

void init(){
    cin>>M>>N;
    for(int i=0;i<1000001;i++){
        num[i]=true;
    }
    num[0]=false;
    num[1]=false;
}

int main(){
    init();
    for(int i=2;i<=sqrt(N);i++){
        for(int j=i*i;j<=N;j+=i){
            num[j]=false;
        }
    }

    for(int i=M;i<=N;i++){
        if(num[i]) printf("%d\n",i);
    }
}