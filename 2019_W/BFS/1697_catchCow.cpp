#include <iostream>
#include <queue>

using namespace std;


//coordinate, day
queue<pair<int,int>> Q;
int x,y;

void init(){
    cin>>x>>y;
    Q.push(make_pair(x,0));
}

void solve(){
    while(true){
        pair<int,int> temp=Q.front();
        if(temp.first==y) {
            cout<<temp.second;
            return;
        }
        else{
            Q.push(make_pair(temp.first+1,temp.second+1));
            Q.push(make_pair(temp.first-1,temp.second+1));
            if(y>temp.first)Q.push(make_pair(temp.first*2,temp.second+1));
        }
        Q.pop();
    }

}

int main(){
    init();
    solve();
    return 0;
}