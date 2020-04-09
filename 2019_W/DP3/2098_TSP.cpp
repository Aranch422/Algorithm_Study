// 경로다르고 거리가 같은게 나왔을때 대처를 못함

#include <iostream>
#include <vector>

using namespace std;

int MAX=987654321;

struct Dist_Visited {
    int dist=MAX;
    bool visited[17]={};
};

int graph[17][17]={};

Dist_Visited dp[17][17];

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
        dp[1][i].dist=graph[1][i];
        dp[1][i].visited[1]=true;
        dp[1][i].visited[i]=true;
    }
}

void solve(){
    //till n-1
    for(int i=2;i<n;i++){
        for(int j=2;j<=n;j++){
            int tempk;
            for(int k=2;k<=n;k++){
                if(dp[i-1][k].visited[j]) continue;
                else{
                    if(graph[k][j]==0) continue;
                    int newdist=dp[i-1][k].dist+graph[k][j];
                    if(newdist<dp[i][j].dist){
                        dp[i][j].dist=newdist;
                        tempk=k;
                    }
                }
            }
            for(int k=2;k<=n;k++){
                dp[i][j].visited[k]=dp[i-1][tempk].visited[k];
            }
            dp[i][j].visited[j]=true;
        }
    }


    for(int j=2;j<=n;j++){
        if(graph[j][1]==0) continue;
        int newdist=dp[n-1][j].dist+graph[j][1];
        if(newdist<dp[n][1].dist){
            dp[n][1].dist=newdist;
        }
    }

    cout<<dp[n][1].dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    solve();
    return 0;
}