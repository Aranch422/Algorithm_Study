#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

/*
int min[1000001];
int max[1000001];
int hsize=0;

int small(int a,int b){
    if(a>b) return a;
    else return b;
}

void insert(int x){
    hsize++;
    min[hsize]=x;
    int idx=hsize;
    int parent=idx/2;
    
    while(parent>0){
        if(min[parent]>min[idx]){
            int temp=min[idx];
            min[idx]=min[parent];
            min[parent]=temp;
        }
        else break;
        idx=parent;
        parent=idx/2;
    }

    max[hsize]=x;
    idx=hsize;
    parent=idx/2;
    while(parent>0){
        if(max[parent]<max[idx]){
            int temp=max[parent];
            max[parent]=max[idx];
            max[idx]=temp;
        }
        else break;
        idx=parent;
        parent=idx/2;
    }
}

bool isEmpty(){
    return hsize==0;
}

void delmin(){
    if(isEmpty()) return;

    min[1]=min[hsize];
    max[1]=max[hsize];
    hsize--;
    int idx=1;
    int left=2; int right=3;
    while(idx<=hsize){
        left=idx*2;
        right=left+1;
        if(left>hsize) break;
        else if(right>hsize){
            if(min[idx]>min[left]){
                int temp=min[idx];
                min[idx]=min[left];
                min[left]=temp;
                idx=left;
            }
            else break;
        }
        else{
            if(min[left]<min[right]){
                if(min[idx]>min[left]){
                    int temp=min[idx];
                    min[idx]=min[left];
                    min[left]=temp;
                    idx=left;
                }
                else break;
            }
            else{
                if(min[idx]>min[right]){
                    int temp=min[idx];
                    min[idx]=min[right];
                    min[right]=temp;
                    idx=right;
                }
                else break;
            }
        }
    }

    while(idx<=hsize){
        left=idx*2;
        right=left+1;
        if(left>hsize) break;
        else if(right>hsize){
            if(max[idx]<max[left]){
                int temp=max[idx];
                max[idx]=max[left];
                max[left]=temp;
                idx=left;
            }
            else break;
        }
        else{
            if(max[left]>max[right]){
                if(max[idx]<max[left]){
                    int temp=max[idx];
                    max[idx]=max[left];
                    max[left]=temp;
                    idx=left;
                }
                else break;
            }
            else{
                if(max[idx]<max[right]){
                    int temp=max[idx];
                    max[idx]=max[right];
                    max[right]=temp;
                    idx=right;
                }
                else break;
            }
        }
    }
}


void solve(){
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        string s;
        cin>>s;
        if(s=="I"){
            int num;
            cin>>num;
            insert(num);
        }
        else{
            int num;
            cin>>num;
            if(num==1){

            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        hsize=0;
        solve();
    }
    return 0;
}

*/

deque<int> dq;
bool isSorted=false;

void insert(int x){
    if(dq.empty()) {
        dq.push_back(x);
        return;
    }
    if(x<=dq.front()) dq.push_front(x);
    else if(dq.back()<=x) dq.push_back(x);
    else{
        dq.push_back(x);
        isSorted=false;
    }
}

void del(int par){
    if(dq.empty()) return;
    if(!isSorted){
        sort(dq.begin(),dq.end());
    }
    if(par==-1) dq.pop_front();
    else dq.pop_back();
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            string s; int num;
            cin>>s>>num;
            if(s=="I") insert(num);
            else del(num);
        }
        if(dq.empty()) cout<<"EMPTY\n";
        else cout<<dq.back()<<" "<<dq.front()<<'\n';
    }
    return 0;
}