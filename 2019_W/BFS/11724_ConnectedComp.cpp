#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int v,e;
bool visited[1001];
vector<int> V[1001];
queue<int> Q;

void init(){
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for(int i=0;i<=v;i++){
        visited[i]=false;
    }
}

int findZero(){
    for(int i=1;i<=v;i++){
        if(visited[i]==false) return i;
    }
    return -1;
}

void solve(){
    Q.push(1);
    int cnt=0;
    while(findZero()!=-1){
        cnt++;
        Q.push(findZero());
        while(!Q.empty()){
            int cur=Q.front();
            Q.pop();
            if(visited[cur]) continue;
            visited[cur]=true;
            for(int i=0;i<V[cur].size();i++){
                if(visited[V[cur][i]]) continue;
                else{
                    Q.push(V[cur][i]);
                }
            }
        }
    }
    cout<<cnt;
}

int main(){
    init();
    solve();
    return 0;
}