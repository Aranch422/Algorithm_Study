#include <iostream>
#include <queue>

using namespace std;

int n,k;

queue<int> myQ;

void init(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        myQ.push(i);
    }
}
void solve(){
    while(!myQ.empty()){
        for(int i=0;i<k-1;i++){
            int temp=myQ.front();
            myQ.pop();
            myQ.push(temp);
        }
        if(myQ.size()==1){
            cout<<myQ.front();
            return;
        }
        cout<<myQ.front()<<", ";
        myQ.pop();
    }
}

int main(){
    init();
    cout<<'<';
    solve();
    cout<<'>';
    return 0;
}