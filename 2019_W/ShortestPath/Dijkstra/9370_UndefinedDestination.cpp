#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int MAX=987654321;

void solve(){
    vector<pair<int,int>> graph[2001];
    int dist[2001];
    int target[100];

    int n,m,t;
    cin>>n>>m>>t;
    
    int start,g,h;
    cin>>start>>g>>h;

    for(int i=1;i<=n;i++){
        dist[i]=MAX;
    }
    for(int i=0;i<m;i++){
        int from,to,w;
        cin>>from>>to>>w;
        graph[from].push_back(make_pair(w,to));
        graph[to].push_back(make_pair(w,from));
    }
    for(int i=0;i<t;i++){
        cin>>target[i];
    }

    //first dijk
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
    PQ.push(make_pair(0,start));
    dist[start]=0;
    while(!PQ.empty()){
        int cur=PQ.top().second;
        int curDist=PQ.top().first;
        PQ.pop();
        if(dist[cur]<curDist) continue;

        for(int i=0;i<graph[cur].size();i++){
            int next=graph[cur][i].second;
            int nextDist=graph[cur][i].first;
            int newDist=curDist+nextDist;
            if(newDist<dist[next]){
                dist[next]=newDist;
                PQ.push(make_pair(newDist,next));
            }
        }
    }
    int newStart;
    if(dist[g]<dist[h]) newStart=h;
    else newStart=g;
    int dist2[2001];

    for(int i=1;i<=n;i++){
        dist2[i]=MAX;
    }

    dist2[newStart]=0;
    PQ.push(make_pair(0,newStart));

    //2nd dijk with newStart,dist2
    while(!PQ.empty()){
        int cur=PQ.top().second;
        int curDist=PQ.top().first;
        PQ.pop();

        if(dist2[cur]<curDist) continue;

        for(int i=0;i<graph[cur].size();i++){
            int next=graph[cur][i].second;
            int nextDist=graph[cur][i].first;
            int newDist=curDist+nextDist;
            if(newDist<dist2[next]){
                dist2[next]=newDist;
                PQ.push(make_pair(newDist,next));
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<t;i++){
        if(dist[newStart]+dist2[target[i]]==dist[target[i]]){
            ans.push_back(target[i]);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin>>k;
    while(k>0){
        k--;
        solve();
    }
    return 0;
}