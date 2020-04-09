#include <iostream>

using namespace std;


int board[50][50]={};
bool isable=false;

int r,c;

void init(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>board[i][j];
        }
    }
}

bool isIn(int curR,int curC){
    return (0<=curR&&curR<r&&0<=curC&&curC<c);
}

bool gocolor(int x1,int y1,int x2,int y2){
    if(isIn(x1,y1)&&isIn(x2,y2)){
        //no 0
        if(board[x1][y1]*board[x2][y2]!=0){
            //no -1 -1
            if(board[x1][y1]+board[x2][y2]>=0){
                return true;
            }
        }
    }
    return false;
}

bool gocolor(int x1,int y1,int x2,int y2,int x3,int y3){
    //inside
    if(isIn(x1,y1)&&isIn(x2,y2)&&isIn(x3,y3)){
        //not 0
        if(board[x1][y1]!=0&&board[x2][y2]!=0&&board[x3][y3]!=0){
            //no all -1
            if(!(board[x1][y1]==-1&&board[x2][y2]==-1&&board[x3][y3]==-1)){
                return true;
            }
        }
    }
    return false;
}

pair<int,int> findBox(){
    for(int i=0;i<r-1;i++){
        for(int j=0;j<c-1;j++){
            if(board[i][j]==1 && board[i][j+1]==1 &&
                board[i+1][j]==1 && board[i+1][j+1]==1){
                    return make_pair(i,j);
            }
        }
    }
    return make_pair(-1,-1);
}

void dfs(int rx,int cy){

    //color -1
    board[rx][cy]=-1;
    board[rx][cy+1]=-1;
    board[rx+1][cy]=-1;
    board[rx+1][cy+1]=-1;

    int x1,y1,x2,y2,x3,y3;

    //right
    x1=rx; y1=cy+2; x2=rx+1; y2=cy+2;
    if(gocolor(x1,y1,x2,y2)) dfs(rx,cy+1); 

    //down
    x1=rx+2; y1=cy; x2=rx+2; y2=cy+1;
    if(gocolor(x1,y1,x2,y2)) dfs(rx+1,cy); 

    //left
    x1=rx; y1=cy-1; x2=rx+1; y2=cy-1;
    if(gocolor(x1,y1,x2,y2)) dfs(rx,cy-1); 

    //up
    x1=rx-1; y1=cy; x2=rx-1; y2=cy+1;
    if(gocolor(x1,y1,x2,y2)) dfs(rx-1,cy); 
    
    //2 colck
    x1=rx-1; y1=cy+1; x2=rx-1; y2=cy+2; x3=rx; y3=cy+2;
    if(gocolor(x1,y1,x2,y2,x3,y3)) dfs(x1,y1);

    //5 colck
    x1=rx+1; y1=cy+2; x2=rx+2; y2=cy+1; x3=rx+2; y3=cy+2;
    if(gocolor(x1,y1,x2,y2,x3,y3)) dfs(rx+1,cy+1);

    //7 colck
    x1=rx+1; y1=cy-1; x2=rx+2; y2=cy-1; x3=rx+2; y3=cy;
    if(gocolor(x1,y1,x2,y2,x3,y3)) dfs(rx+1,cy-1);

    //10 colck
    x1=rx-1; y1=cy-1; x2=rx-1; y2=cy; x3=rx; y3=cy-1;
    if(gocolor(x1,y1,x2,y2,x3,y3)) dfs(x1,y1);
    
    
}

void solve(){
    int x,y;
    pair<int,int> cor=findBox();
    x=cor.first;
    y=cor.second;
    while(x!=-1){

        dfs(x,y);
        
        pair<int,int> cor=findBox();
        x=cor.first;
        y=cor.second;
    }

    isable=true;
    /*
    cout<<"##########res#########\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
           cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    */
   
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]==1){
                isable=false;
                break;
            }
        }
    }
    if(isable) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int rot;
    cin>>rot;
    while(rot>0){
        rot--;
        init();
        solve();
    }
    return 0;
}