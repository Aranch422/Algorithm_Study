#include <iostream>

using namespace std;

int cnt[10];

int main(){
    for(int i=0;i<10;i++){
        cnt[i]=0;
    }
    int a,b,c;
    cin>>a>>b>>c;
    int mul= a*b*c;
    while(mul>0){
        cnt[mul%10]++;
        mul=mul/10;
    }
    for(int i=0;i<10;i++){
        cout<<cnt[i]<<endl;
    }
}