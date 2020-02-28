#include <iostream>
#include <queue>

using namespace std;


//coordinate, day
queue<pair<int,int>> Q;
bool visited[100001];
int x,y;

void init(){
    cin>>x>>y;
    Q.push(make_pair(x,0));
    for(int i=0;i<=100000;i++){
        visited[i]=false;
    }
}

void solve(){
    while(!Q.empty()){
        pair<int,int> temp=Q.front();
        Q.pop();
        visited[temp.first]=true;
        //cout<<temp.first<<" "<<temp.second<<'\n';
        if(temp.first==y) {
            cout<<temp.second;
            return;
        }
        else{
            if(0<=(temp.first+1)&&(temp.first+1)<=100000&&!visited[temp.first+1]) Q.push(make_pair(temp.first+1,temp.second+1));
            if(0<=(temp.first-1)&&(temp.first-1)<=100000&&!visited[temp.first-1]) Q.push(make_pair(temp.first-1,temp.second+1));
            if(0<=(temp.first*2)&&(temp.first*2)<=100000&&!visited[temp.first*2]) Q.push(make_pair(temp.first*2,temp.second+1));
        }
    }
    cout<<-1;
}

int main(){
    init();
    solve();
    return 0;
}