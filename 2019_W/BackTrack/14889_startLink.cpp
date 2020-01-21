#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int n;

int board[20][20];
int team[20];
int Min=40000;


void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        team[i]=0;
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
}

void solve(){

    int start=0;
    int link=0;;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(team[i]==1&&team[j]==1) start+=board[i][j];
            else if(team[i]==0&&team[j]==0) link+=board[i][j];
        }
    }
    if(Min>abs(start-link)) Min=abs(start-link);
}
int cnt=0;
void pick(int k,int level){

    if(level==0) {
        solve();
        return;
    }
    for(int i=k;i<n;i++){
        team[i]=1;
        pick(i+1,level-1);
        team[i]=0;
    }
}

int main(){
    init();
    pick(0,n/2);
    cout<<Min<<endl;
    return 0;
}