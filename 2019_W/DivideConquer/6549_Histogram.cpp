#include <iostream>

using namespace std;

long long n;
long long num[100001];
//ST for index
long long ST[400004];

long long max3(long long a,long long b,long long c){
    if(a<=b){
        if(b<=c) return c;
        else return b;
    }
    else{
        if(a<=c) return c;
        else return a;
    }
}

long long make_ST(long long node,long long start,long long end){
    if(start==end) {
        ST[node]=start;
        return ST[node];
    }
    long long mid=(start+end)/2;
    long long left=make_ST(node*2,start,mid);
    long long right=make_ST(node*2+1,mid+1,end);
    if(num[left]<=num[right]) return ST[node]= left;
    else return ST[node]=right;
}

long long query(long long node,long long start,long long end,long long left,long long right){
    //cout<<start<<" "<<end<<endl;
    if(right<start||end<left){
        return 0;
    }
    if(left<=start&&end<=right){
        return ST[node];
    }
    long long mid=(start+end)/2;
    long long ll=query(node*2,start,mid,left,right);
    long long rr=query(node*2+1,mid+1,end,left,right);
    if(num[ll]<=num[rr]) {
        //cout<<"left "<<ll<<endl;
        return ll;
    }
    else {
        //cout<<"right "<<rr<<endl;
        return rr;
    }
}

long long query2(long long left,long long right){
    //cout<<left<<" "<<right<<" ";
    if(left>right) return 0;
    if(left==right) return num[left];
    long long pos=query(1,1,n,left,right);
    long long value=num[pos]*(right-left+1);
    //cout<<pos<<" "<<value<<endl;
    return max3(query2(left,pos-1),value,query2(pos+1,right));
}

int main(){
    num[0]=2000000000;
    while(1){
        cin>>n;
        if(n==0) return 0;
        for(long long i=1;i<=n;i++){
            cin>>num[i];
        }
        make_ST(1,1,n);
        //cout<<query(1,1,n,3,7);
        /*
        for(long long i=0;i<=13;i++){
            cout<<ST[i]<<" ";
        }
        */
        cout<<query2(1,n)<<"\n";
    }
}