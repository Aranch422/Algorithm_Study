#include <iostream>

using namespace std;

int num[10];
int rem[41];

int main(){
    for(int i=0;i<42;i++){
        rem[i]=0;
    }
    for(int i=0;i<10;i++){
        cin>>num[i];
        num[i]=num[i]%42;
        rem[num[i]]++;
    }
    int cnt=0;
    for(int i=0;i<42;i++){
        if(rem[i]!=0) cnt++;
    }
    cout<<cnt;
    return 0;
}