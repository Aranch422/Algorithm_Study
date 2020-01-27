#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long n,m,k;
long long num[1000010];
long long ST[2000020];

long long make_ST(long long node,long long start,long long end){

    if(start==end){
        ST[node]=num[start];
        return ST[node];
    }
    else{
        ST[node]=make_ST(node*2,start,(start+end)/2)+make_ST(node*2+1,(start+end)/2+1,end);
        return ST[node];
    }
}

long long find_ST(long long node,long long start,long long end,long long left,long long right){
    //outside
    if(end<left||right<start){
        return 0;
    }
    else if(left<=start&&end<=right){
        return ST[node];
    }
    else{
        return find_ST(node*2,start,(start+end)/2,left,right)
        +find_ST(node*2+1,(start+end)/2+1,end,left,right);
    }
}

void change_ST(long long node,long long start,long long end,long long target,long long newValue){

    if(target==start&&target==end){
        long long gap=newValue-ST[node];
        ST[node]=newValue;
        while(node>0){
            node=node/2;
            ST[node]+=gap;
        }
    }
    else if(target<=(start+end)/2){
        change_ST(node*2,start,(start+end)/2,target,newValue);
    }
    else change_ST(node*2+1,(start+end)/2+1,end,target,newValue);
}

void init(){
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    make_ST(1,1,n);
}

int main(){
    /*
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    */
    init();
    /*
    int j=2;
    for(int i=1;i<=pow(2,n);i++){
        cout<<ST[i]<<" ";
        if(i==j-1){
            cout<<"\n";
            j*=2;
        }
    }
    */
    long long time=m+k;
    while(time>0){
        time--;
        long long a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            change_ST(1,1,n,b,c);
        }
        else if(a==2){
            cout<<find_ST(1,1,n,b,c)<<"\n";
        }
    }
}