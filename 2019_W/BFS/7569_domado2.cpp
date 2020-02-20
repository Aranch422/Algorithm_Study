#include <iostream>
#include <queue>

using namespace std;

struct DMD{
    int x,y,z;
    int day;
};

queue<DMD> Q;
int board[100][100][100];

int m,n,h;
int num=0;

int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};


void init(){
    cin>>n>>m>>h;

    for(int z=0;z<h;z++){
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                cin>>board[x][y][z];
                if(board[x][y][z]==0) num++;
                if(board[x][y][z]==1){
                    DMD temp;
                    temp.x=x;
                    temp.y=y;
                    temp.z=z;
                    temp.day=0;
                    Q.push(temp);
                }
            }
        }
    }
}

int day=0;

void solve(){
    while(!Q.empty()){
        DMD temp= Q.front();
        day=temp.day;
        for(int i=0;i<6;i++){
            int newx=temp.x+dx[i];
            int newy=temp.y+dy[i];
            int newz=temp.z+dz[i];

            if(0<=newx&&newx<m && 0<=newy&&newy<n && 0<=newz&&newz<h){
                if(board[newx][newy][newz]==0){
                    //cout<<newx<<" "<<newy<<" "<<newz<<endl;
                    num--;
                    board[newx][newy][newz]=1;
                    DMD forP;
                    forP.x=newx; forP.y=newy; forP.z=newz; forP.day=temp.day+1;

                    Q.push(forP);
                }
            }
        }
        Q.pop();
        /*
        cout<<"========================\n";
        for(int z=0;z<h;z++){
            for(int x=0;x<m;x++){
                for(int y=0;y<n;y++){
                    cout<<board[x][y][z];
                }
                cout<<endl;
            }
            cout<<endl;
        }
        */
    }
    if(num==0)cout<<day;
    else cout<<-1;
}

int main(){
    init();
    solve();    
    return 0;
}