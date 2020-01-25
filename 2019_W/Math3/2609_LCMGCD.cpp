#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int small;
    if(a>b) small=b;
    else small=a;
    int GCD=0;
    for(int i=small;i>=1;i--){
        if(a%i==0&&b%i==0) {
            GCD=i;
            break;
        }
    }
    cout<<GCD<<endl;
    cout<<a*b/GCD<<endl;
}