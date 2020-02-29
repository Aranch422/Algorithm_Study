#include <iostream>

using namespace std;

int r,c,b;
int sum=0;
int Mean=0;

int MIN=2000000000;
int Ans;

int board[500][500];

void init(){
    cin>>r>>c>>b;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>board[i][j];
            sum+=board[i][j];
        }
    }
    sum+=b;
    Mean=sum/(r*c);
}

void solve(){
    int time=0;
    for(int level=0;level<=Mean;level++){
        time=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]-level>0) time+=(board[i][j]-level)*2;
                else time+=(level-board[i][j]);
            }
        }
        if(time<=MIN) {
            MIN=time;
            Ans=level;
        }
    }
}


int main(){
    init();
    solve();
    cout<<MIN<<" "<<Ans;
    return 0;
}