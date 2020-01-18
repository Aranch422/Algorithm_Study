#include <iostream>
#include <string>

using namespace std;

int board[10][10];
bool domino[10][10];


void init(int n){
    //domino init false
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            board[i][j]=0;
            domino[i][j]=false;
            if(i==j) domino[i][j]=true;
        }
    }

    while(n>0){
        n--;
        int a,b;
        string pa,pb;
        cin>>a>>pa>>b>>pb;

        board[pa[0]-'A'+1][pa[1]-'0']=a;
        board[pb[0]-'A'+1][pb[1]-'0']=b;

        domino[a][b]=true;
        domino[b][a]=true;
    }

    for(int i=1;i<10;i++){
        string pi;
        cin>>pi;
        board[pi[0]-'A'+1][pi[1]-'0']=i;
    }
}

bool checkBoard(int r,int c,int num){
    //row
    for(int i=1;i<10;i++){
        if(board[r][i]==num) return false;
    }

    //column
    for(int i=1;i<10;i++){
        if(board[i][c]==num) return false;
    }

    for(int i=((r-1)/3)*3+1;i<((r-1)/3)*3+4;i++){
        for(int j=((c-1)/3)*3+1;j<((c-1)/3)*3+4;j++){
            if(board[i][j]==num) return false;
        }
    }

    return true;
}

//no next return -1,-1
pair<int,int> findnext(int r, int c){

    for(int j=c+1;j<10;j++){
        if(board[r][j]==0){
            return make_pair(r,j);
        }
    }
    
    for(int i=r+1;i<10;i++){
        for(int j=1;j<10;j++){
            if(board[i][j]==0){
                return make_pair(i,j);
            }
        }
    }
    return make_pair(-1,-1);
}


int dfs(int r, int c){

    if(r==-1&&c==-1) return 0;

    for(int k1=1;k1<10;k1++){

        if(checkBoard(r,c,k1)){
            board[r][c]=k1;

            //horizontal
            if(c<9&&board[r][c+1]==0){
                for(int k2=1;k2<10;k2++){
                    //board check & domino check
                    if(checkBoard(r,c+1,k2)&&!domino[k1][k2]){
                        board[r][c+1]=k2;
                        domino[k1][k2]=true;
                        domino[k2][k1]=true;
                        int nextR=findnext(r,c).first;
                        int nextC=findnext(r,c).second;
                        if(dfs(nextR,nextC)==0) return 0;
                        domino[k1][k2]=false;
                        domino[k2][k1]=false;                  
                    }
                }
                board[r][c+1]=0;
            }

            // no space then vertical
            if(r<9&&board[r+1][c]==0){
                for(int k2=1;k2<10;k2++){
                    //board check & domino check
                    if(checkBoard(r+1,c,k2)&&!domino[k1][k2]){
                        board[r+1][c]=k2;

                        int nextR=findnext(r,c).first;
                        int nextC=findnext(r,c).second;

                        domino[k1][k2]=true;
                        domino[k2][k1]=true;
                        if(dfs(nextR,nextC)==0) return 0;
                        domino[k1][k2]=false;
                        domino[k2][k1]=false;
                    }
                }
                board[r+1][c]=0;
            }
        }
    }
    board[r][c]=0;
    return -1;
}

void solve(){
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            if(board[i][j]==0){
                dfs(i,j);
                return;
            }
        }
    }
}



int main(){
    int cnt=1;
    while(cnt>0){
        int n;
        cin>> n;
        if(n==0) return 0;
        init(n);
        solve();

        //out
        cout<<"Puzzle "<<cnt<<endl;
        for(int i=1;i<10;i++){
            for(int j=1;j<10;j++){
                cout<<board[i][j];
            }
            cout<< endl;
        }
        cnt++;
        
    }

    return 0;
}