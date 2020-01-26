#include <iostream>

using namespace std;

long long n,b;

long long** mat;

void init(){
    cin>>n>>b;
    mat=new long long*[n];
    for(long long i=0;i<n;i++){
        mat[i]=new long long[n];
    }

    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            cin>>mat[i][j];
            mat[i][j]=mat[i][j]%1000;
        }
    }
}

long long** mul(long long** a,long long** b){
    long long** ret;
    ret=new long long*[n];
    for(long long i=0;i<n;i++){
        ret[i]=new long long[n];
    }

    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            long long temp=0;
            for(long long k=0;k<n;k++){
                temp+=a[i][k]*b[k][j];
                temp%1000;
            }
            ret[i][j]=temp%1000;
        }
    }
    return ret;
}

long long** MatExp(long long level){
    if(level==1) return mat;
    else if(level%2==1) return mul(mat,MatExp(level-1));
    else{
        long long** half = MatExp(level/2);
        return mul(half,half);
    }
}

int main(){
    init();
    long long** ans=MatExp(b);
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}