#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int,int>> graph[801];

int MAX=300000000;

int v,e;
int a,b;

void init(){
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int from,to,w;
        cin>>from>>to>>w;
        graph[from].push_back(make_pair(w,to));
        graph[to].push_back(make_pair(w,from));
    }
    cin>>a>>b;
}

int Dijk(int start,int end){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
    int dist[801];
    for(int i=1;i<=v;i++) dist[i]=MAX;

    dist[start]=0;
    PQ.push(make_pair(0,start));

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
    /*
    for(int i=1;i<=v;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    cout<<end<<" "<<dist[end]<<endl;
    */
    return dist[end];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int sa,be,sb,ae;
    sa=Dijk(1,a);
    sb=Dijk(1,b);
    be=Dijk(b,v);
    ae=Dijk(a,v);
    int bridge=Dijk(a,b);

    int first=sa+bridge+be;
    int second=sb+bridge+ae;
    int small = (first<second)? first:second;
    /*
    cout<<sa<<" "<<be<<endl;
    cout<<sb<<" "<<ae<<endl;
    cout<<bridge<<endl;
    cout<<endl;
    */
    if(small<MAX) cout<<small;
    else cout<<-1;

    return 0;
}