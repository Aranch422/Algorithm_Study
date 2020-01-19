#include <iostream>

using namespace std;

bool isdoom(int n){
    int cnt=0;
    while(n>0){
        int temp=n%10;
        if(temp==6) cnt++;
        else cnt=0;
        if(cnt==3) return true;
        n=n/10;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int cnt=0;
    int ret;
    for(int i=0;cnt!=n;i++){
        if(isdoom(i)) {
            cnt++;
            ret=i;
        }
    }
    cout<<ret<<endl;

    return 0;
}