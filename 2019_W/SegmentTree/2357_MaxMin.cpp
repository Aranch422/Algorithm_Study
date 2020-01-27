#include <iostream>
#include <algorithm>

using namespace std;

int n,m;

int MAX=2000000000;
int MIN=0;

int num[100001];
int STbig[400004];
int STsmall[400004];

long long make_STbig(int node,int start,int end){
    if(start==end){
        STbig[node]=num[start];
        return STbig[node];
    }
    else{
        int mid=(start+end)/2;
        STbig[node]=max(make_STbig(node*2,start,mid),make_STbig(node*2+1,mid+1,end));
        return STbig[node];
    }
}

long long make_STsmall(int node,int start,int end){
    if(start==end){
        STsmall[node]=num[start];
        return STsmall[node];
    }
    else{
        int mid=(start+end)/2;
        STsmall[node]=min(make_STsmall(node*2,start,mid),make_STsmall(node*2+1,mid+1,end));
        return STsmall[node];
    }
}

int queryMax(int node, int start,int end,int left,int right){
    if(right<start||end<left) return MIN;
    if(left<=start&&end<=right) return STbig[node];
    int mid=(start+end)/2;
    return max(queryMax(node*2,start,mid,left,right),queryMax(node*2+1,mid+1,end,left,right));
}

int queryMin(int node, int start,int end,int left,int right){
    if(right<start||end<left) return MAX;
    if(left<=start&&end<=right) return STsmall[node];
    int mid=(start+end)/2;
    return min(queryMin(node*2,start,mid,left,right),queryMin(node*2+1,mid+1,end,left,right));
}

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    make_STbig(1,1,n);
    make_STsmall(1,1,n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    while(m>0){
        m--;
        int a,b;
        cin>>a>>b;
        cout<<queryMin(1,1,n,a,b)<<" "<<queryMax(1,1,n,a,b)<<"\n";
    }
    /*
    int j=2;
    for(int i=1;i<=60;i++){
        cout<<STbig[i]<<" ";
        if(i==j-1){
            cout<<endl;
            j*=2;
        }
    }
    cout<<endl;
    j=2;
    for(int i=1;i<=60;i++){
        cout<<STsmall[i]<<" ";
        if(i==j-1){
            cout<<endl;
            j*=2;
        }
    }
    */
    return 0;
}
