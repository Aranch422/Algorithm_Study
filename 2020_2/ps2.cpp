#include <iostream>

using namespace std;

int color[1000];
int dp[1000];
int n;
void init(){
    for (int i=0;i<1000;i++){
        dp[i]=-2;
    }
}

bool check(int s,int e){
    int len=e-s+1;
    len=len/2;
    int one=0;
    int two=0;
    int three=0;
    for (int i=s;i<=e;i++){
        if(color[i]==1) one++;
        if(color[i]==2) two++;
        if(color[i]==3) three++;
    }

    if(one<=len && two<=len && three<=len) {
        cout<<s<<" "<<e<<" true\n";
        return true;
    }
    else{
        cout<<s<<" "<<e<<" false\n";
        return false;
    }
}

int sol(int s){
    if(s==n) return -1;

    if(dp[s]!=-2) return dp[s];

    if(check(s,n))
        dp[s]=0;
    else
        dp[s]=-1;
    
    for (int i=n-1;i>=s+1;i--){
        if(check(s,i)){
            if(dp[i+1]>=0){
                if(dp[i+1]+1>dp[s]){
                    dp[s]=dp[i+1]+1;
                }
            }
            else if(dp[i+1]==-2){
                cout<<"solution called "<<i+1<<endl;
                int ret=sol(i+1);
                if(ret+1>dp[s]){
                    dp[s]=ret+1;
                }
            }
        }
    }
    return dp[s];
}

int main(){
    init();
    color[1]=1;
    color[2]=1;
    color[3]=2;
    color[4]=3;
    color[5]=2;
    color[6]=3;
    n=4;
    cout<<"The answer is "<<sol(1)<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<dp[i]<<endl;
    }
    return 0;
}