#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int num[500001];
int target[500001];

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n);
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>target[i];
    }
}

int BS(int T,int left,int right){
    if(left==right){
        if(num[left]==T){
            int cnt=1;
            int temp=left+1;
            while(num[temp]==T&&temp<n){
                cnt++;
                temp++;
            }
            temp==left-1;
            while(num[temp]==T&&temp>=0){
                cnt++;
                temp--;
            }
            return cnt;
        }
        else return 0;
    }

    int mid=(left+right)/2;
    
    if(T<=num[mid]){
        return BS(T,left,mid);
    }
    else return BS(T,mid+1,right);
}

void solve(){
    for(int i=0;i<m;i++){
        cout<<BS(target[i],0,n-1)<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    solve();

    return 0;
}