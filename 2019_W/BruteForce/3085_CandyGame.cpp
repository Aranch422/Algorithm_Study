#include <iostream>

using namespace std;

char Board[50][50];
int N;

void init(){

    cin >>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>Board[i][j];
        }
    }
}

int up(int r, int c){
    int cnt=0;
    int newR=r-1;
    while (newR>=0){
        if(Board[newR][c]==Board[r][c]){
            cnt++;
            newR--;
        }
        else break;
    }
    return cnt;
}

int down(int r, int c){
    int cnt=0;
    int newR=r+1;
    while(newR<N){
        if(Board[newR][c]==Board[r][c]){
            cnt++;
            newR++;
        }
        else break;
    }
    return cnt;
}

int left(int r, int c){
    int cnt=0;
    int newC=c-1;
    while(newC>=0){
        if(Board[r][newC]==Board[r][c]){
            cnt++;
            newC--;
        }
        else break;
    }
    return cnt;
}

int right(int r, int c){
    int cnt=0;
    int newC=c+1;
    while(newC<N){
        if(Board[r][newC]==Board[r][c]){
            cnt++;
            newC++;
        }
        else break;
    }
    return cnt;
}

int len(int r, int c){
    int L1 = right(r,c)+left(r,c)+1;
    int L2 = up(r,c)+down(r,c)+1;
    return L1>L2? L1:L2;
}

int length[50][50];

int dr[4]={0,-1,0,1};
int dc[4]={-1,0,1,0};

void swap(int r, int c, int rr, int cc){
    char temp;
    temp = Board[r][c];
    Board[r][c]= Board[rr][cc];
    Board[rr][cc]= temp;
}

int swapCal(int r, int c, int k){
    if(r+dr[k]<0 || r+dr[k]>=N || c+dc[k]<0 || c+dc[k]>=N) return -1;

    swap(r,c,r+dr[k],c+dc[k]);
    int ret =len(r,c);
    swap(r,c,r+dr[k],c+dc[k]);
    return ret;
}


int solve(){
    int max=0;
    //set length
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            length[i][j]=len(i,j);
            if(length[i][j]>max){
                max=length[i][j];
            }
        }
    }


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<4;k++){
                if(swapCal(i,j,k)>max){
                    max=swapCal(i,j,k);
                }
            }
        }
    }
    return max;
}

int main(){
    init();
    cout << solve();
}