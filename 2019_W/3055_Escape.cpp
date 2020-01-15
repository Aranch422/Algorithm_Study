#include <iostream>
#include <queue>

using namespace std;

int R,C;

char** Board;
bool** visit;
int x1,y1,x2,y2;
queue<pair<int,int>> Water;

void init() {
    cin>>R>>C;

    //visit false로 초기화
    visit= new bool*[R];
    for (int i=0; i<R;i++){
        visit[i]=new bool[C];
    }
    for (int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            visit[i][j]=false;
        }
    }

    //Board 생성 input
    Board = new char*[R];
    for(int i=0;i<R;i++){
        Board[i]=new char[C];
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>Board[i][j];
            if(Board[i][j]=='S'){
                x1=i;
                y1=j;
            }
            if(Board[i][j]=='D'){
                x2=i;
                y2=j;
            }
            if(Board[i][j]=='*'){
                visit[i][j]=true;
                Water.push(make_pair(i,j));
            }
            if(Board[i][j]=='X'){
                visit[i][j]=true;
            }
        }
    }
}

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void BFS(int x,int y){
    queue<pair<pair<int,int>,int>> myQ;
    myQ.push(make_pair(make_pair(x,y),0));
    visit[x][y]=true;

    while(myQ.empty()!=true){
        /*
        for (int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout << visit[i][j];
            }
            cout<<endl;
        }
        cout<<"====================\n";
        */
       
        //물 먼저
        int sizeW = Water.size();
        for(int i=0;i<sizeW;i++){
            int wx = Water.front().first;
            int wy = Water.front().second;
            visit[wx][wy]==true;

            for(int i=0;i<4;i++){
                int nnx = wx+dx[i];
                int nny = wy+dy[i];

                if(nnx>=0 && nnx<R && nny>=0 && nny<C){
                    if(visit[nnx][nny]==false&& Board[nnx][nny]!='D'){
                        
                        visit[nnx][nny]=true;
                        Water.push(make_pair(nnx,nny));
                    }
                }
            }          
            Water.pop();
        }
        
        
        int sizeQ = myQ.size();

        for(int k=0;k<sizeQ;k++){
            
            int x = myQ.front().first.first;
            int y = myQ.front().first.second;
            int cnt = myQ.front().second;
            myQ.pop();

            if (x == x2 && y == y2)
            {
                cout << cnt << endl;
                return;
            }


            for (int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];

                if (nx >= 0 && ny >= 0 && nx < R && ny < C)
                {
                    if (visit[nx][ny] == false)
                    {
                        visit[nx][ny] = true;
                        myQ.push(make_pair(make_pair(nx, ny), cnt + 1));
                    }
                }

            }
        }

    }

    cout << "KAKTUS";

}

int main(){
    init();
    BFS(x1,y1);
    return 0;
}