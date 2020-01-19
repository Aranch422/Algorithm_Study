#include <iostream>

using namespace std;

int n;

int value[10001];

void init(){
    cin>>n;
    for(int i=0;i<10001;i++){
        value[i]=0;
    }
}

int main(){

    init();
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        value[temp]++;
    }
    for(int i=1;i<=10000;i++){
        for(int j=value[i];j>0;j--){
            printf("%d\n",i);
        }
    }
    return 0;
}