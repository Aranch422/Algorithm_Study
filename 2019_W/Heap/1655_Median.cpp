#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int Heap[100001];

int n;
int Size=0;

void init(){
    cin>>n;
}

void insertH(int k){
    Size++;
    Heap[Size]=k;
    int idx=Size;
    while(idx/2>0){
        int parent=idx/2;
        if(Heap[idx]<Heap[parent]){
            int temp= Heap[idx];
            Heap[idx]=Heap[parent];
            Heap[parent]=temp;
        }
        else break;
        idx=parent;
    }
}

int delH() {
    int ret=Heap[1];
    Heap[1]=Heap[Size];
    Size--;
    int idx=1;
    while(idx*2<=Size){

        int left=idx*2;
        int right=idx*2+1;
        //only left
        if(right>Size){
            if(Heap[left]<Heap[idx]){
                int temp=Heap[left];
                Heap[left]=Heap[idx];
                Heap[idx]=temp;
                idx=left;
            }
            else break;
        }
        //both
        else{
            if(Heap[left]<Heap[right]){
                if(Heap[left]<Heap[idx]){
                    int temp=Heap[left];
                    Heap[left]=Heap[idx];
                    Heap[idx]=temp;
                    idx=left;
                }
                else break;
            }
            else {
                if(Heap[right]<Heap[idx]){
                    int temp=Heap[right];
                    Heap[right]=Heap[idx];
                    Heap[idx]=temp;
                    idx=right;  
                }
                else break;
            }        
        }
    }
    return ret;
}

void solve() {
    for(int i=1;i<=n;i++){
        stack<int> myS;
        int num;
        cin>>num;
        insertH(num);

        /*
        cout<<"HEAP: ";
        for(int j=1;j<=Size;j++){
            cout<<Heap[j]<<" ";
        }
        cout<<endl;
        */

        int mid;
        if(i%2==1) mid=i/2+1;
        else mid=i/2;
        for(int j=1;j<=mid;j++){
            myS.push(delH());
        }
        //result
        cout<<myS.top()<<"\n";

        for(int j=1;j<=mid;j++){
            insertH(myS.top());
            myS.pop();
        }
        /*
        cout<<"HEAP2: ";
        for(int j=1;j<=Size;j++){
            cout<<Heap[j]<<" ";
        }
        cout<<endl;
        */
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