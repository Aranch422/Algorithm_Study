#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int MAX=98765431;

int v,e,start;

//to dist
vector<pair<int,int>> Edge[20001];
int cost[20001];

void init(){
    cin>>v>>e>>start;
    for(int i=1;i<=v;i++){
        cost[i]=MAX;
    }
    for(int i=1;i<=e;i++){
        int from,to,dist;
        cin>>from>>to>>dist;
        Edge[from].push_back(make_pair(to,dist));
    }
}

void solve(){
    //dist ,dest
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
    cost[start]=0;
    PQ.push(make_pair(0,start));
    while(!PQ.empty()){
        int cur =PQ.top().second;
        int dist=PQ.top().first;
        PQ.pop();
        //cout<<"cur dist "<<cur<<" "<<dist<<endl;;
        if(cost[cur]<dist) continue;
        //cout<<"go\n";
        //update
        //cost[cur]=dist;
        /*
        for(int i=1;i<=v;i++){
            cout<<cost[i]<<" ";
        }
        */
        //cout<<endl;
        for(int i=0;i<Edge[cur].size();i++){
            int tempTo=Edge[cur][i].first;
            int tempDist=Edge[cur][i].second;
            int newdist = dist+tempDist;
            if(newdist<cost[tempTo]){
                cost[tempTo]=newdist;
                PQ.push(make_pair(newdist,tempTo));
            }
        }
    }
    for(int i=1;i<=v;i++){
        if(cost[i]==MAX) cout<<"INF\n";
        else cout<<cost[i]<<'\n';
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