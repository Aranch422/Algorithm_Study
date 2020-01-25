#include <iostream>

using namespace std;

int n,target;
int num[100];
int prime[1001];

void init(){
    cin>>n;
    cin>>target;

    //input
    for(int i=0;i<n-1;i++){
        cin>>num[i];
    }

    //init prime
    for(int i=0;i<1001;i++){
        prime[i]=0;
    }

    //set prime
    for(int i=2;i<=32;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=1000;){
                prime[j]=1;
                j=j+i*i;
            }
        }
    }
}

void solve(int a,int b){
    int Min=0;
    if(a<b) Min=a;
    else Min=b;

    for(int i=2;i<=Min;i++){
        //escape
        if(a==1||b==1){
            break;
        }
        if(prime[i]==0&&a%i==0&&b%i==0){
            a=a/i;
            b=b/i;
            i=1;
        }
    }

    cout<<a<<'/'<<b<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    init();
    for(int i=0;i<n-1;i++){
        solve(target,num[i]);
    }
    return 0;
}