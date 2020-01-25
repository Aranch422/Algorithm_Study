#include <iostream>

using namespace std;

int prime[10000001];

void init(){
    for(int i=0;i<10000001;i++){
        prime[i]=0;
    }
    for(int i=2;i<3163;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=10000000;){
                prime[j]=1;
                j+=i*i;
            }
        }
    }
}

void find(int n){
    if(n==1) return;
    else{
        for(int i=2;i<=n;i++){
            if(prime[i]==0&&n%i==0){
                cout<<i<<"\n";
                find(n/i);
                return;
            }
        }
    }
}

int main(){
    init();
    int n;
    cin>>n;
    find(n);
    return 0;
}