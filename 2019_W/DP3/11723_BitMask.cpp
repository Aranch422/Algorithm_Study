#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    bool bit[21]={};
    while(n>0){
        n--;
        string s;
        cin>>s;
        if(s=="add"){
            int num;
            cin>>num;
            bit[num]=1;
        }
        if(s=="remove"){
            int num;
            cin>>num;
            bit[num]=0;
        }
        if(s=="check") {
            int num;
            cin>>num;
            cout<<bit[num]<<'\n';
        }
        if(s=="toggle"){
            int num;
            cin>>num;
            bit[num]=!bit[num];
        }
        if(s=="all"){
            for(int i=1;i<=20;i++){
                bit[i]=1;
            }
        }
        if(s=="empty"){
            for(int i=1;i<=20;i++){
                bit[i]=0;
            }
        }
    }
    return 0;
}