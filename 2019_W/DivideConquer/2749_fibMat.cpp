#include <iostream>

using namespace std;

long long n;
long long R=1000000;

long long** base;

void init(){
    cin>>n;
    base=new long long*[2];
    base[0]= new long long[2];
    base[1]= new long long[2];
    base[0][0]=1;
    base[0][1]=1;
    base[1][0]=1;
    base[1][1]=0;
}

long long** mul(long long** a,long long** b){
    long long** ret= new long long*[2];
    for(int i=0;i<2;i++){
        ret[i]=new long long[2];
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            long long temp=0;
            for(int k=0;k<2;k++){
                temp+=a[i][k]*b[k][j];
                temp=temp%R;
            }
            ret[i][j]=temp%R;
        }
    }
    return ret;
}


//call n when you want n+2
long long** FibMat(long long level){
    if(level==1) return base;
    else{
        if(level%2==1) return mul(base,FibMat(level-1));
        else{
            long long** half=FibMat(level/2);
            return mul(half,half);
        }
    }
}

int main(){
    init();
    if(n==0) cout<<0;
    else if(n==1) cout<<1;
    else{
        long long** ans=FibMat(n-1);
        cout<<ans[0][0];
    }
}