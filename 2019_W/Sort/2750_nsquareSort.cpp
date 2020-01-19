#include <iostream>

using namespace std;

int num[1000];

int n;

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
}

void sort(){
    for(int i=0;i<n;i++){
        int min=10000;
        int tempidx;
        for(int j=i;j<n;j++){
            if(min>num[j]){
                min=num[j];
                tempidx=j;
            } 
        }
        num[tempidx]=num[i];
        num[i]=min;
    }
}

int main(){
    init();
    sort();
    for(int i=0;i<n;i++){
        cout<<num[i]<<"\n";
    }
    return 0;
}