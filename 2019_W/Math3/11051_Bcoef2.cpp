#include <iostream>

using namespace std;
int NK[1001][1001];

void init(){
    //NK init
    for(int n=0;n<1001;n++){
        for(int k=0;k<=n;k++){
            if(k==0){
                NK[n][k]=1;
            }
            else if(n==k){
                NK[n][k]=1;
            }
            else{
                NK[n][k]=(NK[n-1][k-1]+NK[n-1][k])%10007;
            }
        }
    }

}

int main(){
    int n,k;
    cin>>n>>k;
    init();
    cout<<NK[n][k]%10007;

}