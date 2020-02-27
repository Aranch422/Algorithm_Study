#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int cnt=0;

queue<int> Q;
vector<int> V[101];
bool visited[101];
int vertex,edge;

void init(){
    cin>>vertex>>edge;
    for(int i=1;i<=vertex;i++){
        visited[i]=false;
    }
    for(int i=1;i<=edge;i++){
        int a,b;
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
}

void BFS(){
    if(Q.empty()) return;
    int cur=Q.front();
    Q.pop();
    if(visited[cur]){
        BFS();
    }
    else{
        visited[cur]=true;
        cnt++;
        for(int i=0;i<V[cur].size();i++){
            if(visited[V[cur][i]]) continue;
            else{
                Q.push(V[cur][i]);
            }
        }
        BFS();
    }
}

void solve(){
    Q.push(1);
    BFS();
}

int main(){
    init();
    solve();
    cout<<cnt-1;
    return 0;
}