#include <iostream>
#include <string>

using namespace std;

int n;
char board[2200][2200];

void draw(int r,int c, int level){
    if(level ==3){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==1&&j==1) continue;
                board[r+i][c+j]='*';
            }
        }
        return;
    }
    level=level/3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1&&j==1) continue;
            draw(r+i*level,c+j*level,level);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=' ';
        }
    }
    draw(0,0,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j];
        }
        cout<<"\n";
    }
    return 0;
}

