#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

//***dp[x][y]***
int dp[1001][1001];
pair<int,int> before[1001][1001];

int n,kk;

pair<int,int> pos[1001];

int dist(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

void init(){
    cin>>n>>kk;
    for(int i=1;i<=kk;i++){
        int r,c;
        cin>>r>>c;
        pos[i]=make_pair(r,c);
    }
    dp[0][0]=0;
    dp[0][1]=dist(pos[1],make_pair(n,n));
    dp[1][0]=dist(pos[1],make_pair(1,1));
    for(int i=2;i<=kk;i++){
        dp[0][i]=dp[0][i-1]+dist(pos[i-1],pos[i]);
        before[0][i]=make_pair(0,i-1);
        dp[i][0]=dp[i-1][0]+dist(pos[i-1],pos[i]);
        before[i][0]=make_pair(i-1,0);
    }
    for(int i=1;i<=kk;i++){
        for(int j=1;j<=kk;j++){

            if(i==j) continue;

            if(i>j){
                if(i==(j+1)){
                    int MIN=987654321;
                    int temp,tempk;
                    for(int k=0;k<=j-1;k++){
                        if(k==0) pos[0]=make_pair(1,1);
                        temp=dp[k][j]+dist(pos[k],pos[i]);

                        if(temp<MIN){
                            MIN=temp;
                            tempk=k;
                        }
                    }
                    dp[i][j]=MIN;
                    before[i][j]=make_pair(tempk,j);
                }
                else{
                    dp[i][j]=dp[i-1][j]+dist(pos[i-1],pos[i]);
                    before[i][j]=make_pair(i-1,j);
                }
            }
            else{
                if(j==(i+1)){
                    int MIN=987654321;
                    int temp,tempk;
                    for(int k=0;k<=i-1;k++){
                        if(k==0) pos[0]=make_pair(n,n);
                        temp=dp[i][k]+dist(pos[k],pos[j]);

                        if(temp<MIN){
                            MIN=temp;
                            tempk=k;
                        }
                    }
                    dp[i][j]=MIN;
                    before[i][j]=make_pair(i,tempk);
                }
                else{
                    dp[i][j]=dp[i][j-1]+dist(pos[j-1],pos[j]);
                    before[i][j]=make_pair(i,j-1);
                }
            }
        }
    }
}

void solve(){
    int MIN=987654321;
    int r,c;
    for(int i=0;i<kk;i++){
        if(dp[i][kk]<MIN) {
            MIN=dp[i][kk];
            r=i; c=kk;
        }

        if(dp[kk][i]<MIN) {
            MIN=dp[kk][i];
            r=kk; c=i;
        }
    }
    cout<<dp[r][c]<<'\n';
    stack<int> S;

    int temp=kk;
    while(temp>0){
        temp--;
        int newr=before[r][c].first; 
        int newc=before[r][c].second;
        if(newr==r) S.push(2);
        else S.push(1);
        r=newr; c=newc;
    }
    while(!S.empty()){
        cout<<S.top()<<'\n';
        S.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    solve();
    /*
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return 0;
}