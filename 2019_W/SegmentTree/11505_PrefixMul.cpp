#include <iostream>

using namespace std;

long long R=1000000007;
int n,m,k;
long long num[1000001];
long long ST[2000002]; 

long long make_ST(int node,int start,int end){
    if(start==end){
        ST[node]=num[start]%R;
        return ST[node];
    }
    else{
        ST[node]=(make_ST(node*2,start,(start+end)/2)*make_ST(node*2+1,(start+end)/2+1,end))%R;
        return ST[node];
    }
}

long long find_ST(int node,int start,int end,int left,int right){
    if(end<left||right<start){
        return 1;
    }
    else if(left<=start&&end<=right){
        return ST[node];
    }
    else{
        return (find_ST(node*2,start,(start+end)/2,left,right)
        *find_ST(node*2+1,(start+end)/2+1,end,left,right))%R;
    }
}

long long change_ST(int node,int start,int end,int target,long long newValue){
    if(target<start||end<target){
        return ST[node];
    }
    if(start==end) return ST[node]=newValue;

    ST[node] = (change_ST(node*2,start,(start+end)/2,target,newValue)
    * change_ST(node*2+1,(start+end)/2+1,end,target,newValue))%R;
    return ST[node];
}

void init(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }

    make_ST(1,1,n);
}

int main(){
    init();
    long long time=m+k;
    while(time>0){
        time--;
        long long a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            change_ST(1,1,n,b,c);
        }
        else if(a==2){
            cout<<find_ST(1,1,n,b,c)<<endl;
        }
    }
    /*
    for(int i=1;i<=n;i++){
        cout<<num[i]<<" ";
    }
    */
    return 0;
}