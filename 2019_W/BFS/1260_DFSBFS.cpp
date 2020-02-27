#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int board[1001][10001];
bool visited[1001];

stack<int> S;
queue<int> Q;

int V,E,target;

void init(){
    memset(board,-1,sizeof(board));
    for(int i=1;i<=V;i++) visited[i]=false;
    cin>>V>>E>>target;
    for(int i=1;i<=E;i++){
        int vertex,edge;
        cin>>vertex>>edge;
        int numEdge;
        if(board[vertex][0]==-1){
            board[vertex][0]=1;
        }
        else board[vertex][0]++;
        numEdge=board[vertex][0];
        board[vertex][numEdge]=edge;

        //indirected graph
        int temp=vertex;
        vertex=edge; edge=temp;
        if(board[vertex][0]==-1){
            board[vertex][0]=1;
        }
        else board[vertex][0]++;
        numEdge=board[vertex][0];
        board[vertex][numEdge]=edge;
    }
    for(int i=1;i<=V;i++){
        if(board[i][0]!=-1) sort(board[i]+1,board[i]+1+board[i][0]);
    }

}

void DFS(){
    if(S.empty()) return;
    int cur = S.top();
    if(visited[cur]) return;
    visited[cur]=true;
    cout<<cur<<" ";
    bool isLeaf =true;
    for(int i=1;board[cur][i]!=-1;i++){
        //already visited
        if(visited[board[cur][i]]){
            continue;
        }
        else{
            isLeaf=false;
            S.push(board[cur][i]);
            DFS();
        }
    }
    if(isLeaf){
        S.pop();
        DFS();
    }
}

void BFS(){
    if(Q.empty()) return;
    int cur =Q.front();
    Q.pop();
    if(visited[cur]) {
        BFS();
        return;
    }
    cout<<cur<<" ";
    visited[cur]=true;
    for(int i=1;board[cur][i]!=-1;i++){
        //already visited
        if(visited[board[cur][i]]) continue;
        else{
            Q.push(board[cur][i]);
        }
    }
    BFS();
}

void solve(){
    S.push(target);
    DFS();
    for(int i=0;i<=V;i++){
        visited[i]=false;
    }
    cout<<'\n';
    Q.push(target);
    BFS();
}

int main(){
    
    init();

    //show board
    /*
    for(int r=1;r<=V;r++){
        for(int c=0;c<=E;c++){
            cout<<board[r][c]<<" ";
        }
        cout<<endl;
    }
    */
    
    solve();
    

    return 0;
}