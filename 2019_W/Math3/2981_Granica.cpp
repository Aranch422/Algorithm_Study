#include <iostream>

using namespace std;

int n;
int num[100];
int Max=0;
void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        if(Max<num[i]) Max=num[i];
    }
}

int main(){
    for(int i=2;i<=Max+1;i++){
        
    }
    return 0;
}