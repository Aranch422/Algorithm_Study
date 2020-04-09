//경로 다르고 거리 같을때 대처 가능하나 너무 많으면 터짐

#include <iostream>
#include <vector>

using namespace std;

int MAX=987654321;

struct Dist_Visited {
    int dist=MAX;
    int cur=0;
    bool visited[17]={};
    Dist_Visited(int Dist,int Cur){
        dist=Dist;
        cur=Cur;
    }
};

int graph[17][17]={};

vector<Dist_Visited> dp[17];

int n;

void init(){

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>graph[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(graph[1][i]==0) continue;
        Dist_Visited temp= Dist_Visited(graph[1][i],i);
        temp.visited[1]=true;
        temp.visited[i]=true;
        dp[1].push_back(temp);
    }
}

void solve(){
    //till n-1
    for(int i=2;i<n;i++){
        cout<<i<<endl;
        int tempcur;
        cout<<"size "<<dp[i-1].size()<<" ";
        for(int j=2;j<=n;j++){
            cout<<j<<" ";
            int tempdist=MAX;
            vector<Dist_Visited> pushList;
            
            for(int k=0;k<dp[i-1].size();k++){

                if(dp[i-1][k].visited[j]) continue;
                int mid=dp[i-1][k].cur;
                if(graph[mid][j]==0) continue;
                int newdist=dp[i-1][k].dist+graph[mid][j];

                if(newdist<tempdist){

                    tempdist=newdist;
                    while(!pushList.empty()){
                        pushList.pop_back();
                    }

                    //make pushlist elem
                    Dist_Visited elem= Dist_Visited(newdist,j);
                    for(int idx=0;idx<=n;idx++){
                        elem.visited[idx]=dp[i-1][k].visited[idx];
                    }
                    elem.visited[j]=true;
                    pushList.push_back(elem);
                }

                else if(newdist==tempdist){
                    //make pushlist elem
                    Dist_Visited elem= Dist_Visited(newdist,j);
                    for(int idx=0;idx<=n;idx++){
                        elem.visited[idx]=dp[i-1][k].visited[idx];
                    }
                    elem.visited[j]=true;
                    pushList.push_back(elem);
                }
            }

            for(int k=0;k<pushList.size();k++){
                dp[i].push_back(pushList[k]);
            }
        }
        cout<<endl;
    }

    int minimum=MAX;

    for(int j=0;j<dp[n-1].size();j++){
        int cur =dp[n-1][j].cur;
        if(graph[cur][1]==0) continue;
        int newdist=dp[n-1][j].dist+graph[cur][1];
        if(newdist<minimum)
            minimum=newdist;
    }
    cout<<minimum;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    cout<<"start\n";
    init();
    cout<<"init end\n";
    solve();
    return 0;
}