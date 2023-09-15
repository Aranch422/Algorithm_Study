#include <iostream>
#include <vector>

using namespace std;

struct Shark{
    bool isAlive;
    int r,c;
    int speed;
    int dir;
    int size;
};

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,1,-1};

vector<Shark*> board[100][100];
Shark sharks[10000];

int main(){
    int R,C,M;
    cin>>R>>C>>M;
    for(int i=0;i<M;i++){
        int r,c,s,d,z;
        cin>>r>>c>>s>>d>>z;
        sharks[i].isAlive = true;
        sharks[i].r = r-1;
        sharks[i].c = c-1;
        sharks[i].speed = s;
        sharks[i].dir = d-1;
        sharks[i].size = z;
        board[r-1][c-1].push_back(&sharks[i]);
    }
    
    int ret = 0;
    int player = 0;
    while(player<C){
        for(int i=0;i<R;i++){
            if(board[i][player].size() != 0){
                board[i][player][0]->isAlive = false;
                ret += board[i][player][0]->size;
                //cout<<board[i][player][0]->size<<endl;
                break;
            }
        }

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){ 
                if(board[i][j].size()!=0){
                    board[i][j].pop_back();
                }
            }
        }
        
        for(int i=0;i<M;i++){
            if(sharks[i].isAlive){
                int speed = sharks[i].speed;
                int tempR = sharks[i].r+dr[sharks[i].dir]*speed;
                int tempC = sharks[i].c+dc[sharks[i].dir]*speed;
                if(dr[sharks[i].dir] !=0){
                    int cnt = 0;
                    if(tempR<0){
                        tempR = -tempR;
                        cnt++;
                    }
                    if((tempR/(R-1))%2 ==1){
                        cnt++;
                    }
                    tempR = tempR%(2*(R-1));
                    if(tempR > (R-1)){
                        tempR -= (R-1);
                        tempR = (R-1)-tempR;
                    }
                    if(cnt == 1){
                        if(sharks[i].dir == 0){
                            sharks[i].dir =1;
                        }
                        else if(sharks[i].dir == 1){
                            sharks[i].dir =0;
                        }
                    }
                }
                else if(dc[sharks[i].dir] != 0 ){
                    int cnt = 0;
                    if(tempC<0){
                        tempC = -tempC;
                        cnt++;
                    }
                    if((tempC/(C-1))%2 ==1){
                        cnt++;
                    }
                    tempC = tempC%(2*(C-1));
                    if(tempC > (C-1)){
                        tempC -= (C-1);
                        tempC = (C-1)-tempC;

                    }
                    if(cnt == 1){
                        if(sharks[i].dir == 2){
                            sharks[i].dir =3;
                        }
                        else if(sharks[i].dir == 3){
                            sharks[i].dir =2;
                        }
                    }
                }
                sharks[i].r = tempR;
                sharks[i].c = tempC;
                if(board[tempR][tempC].size()!=0){
                    if(sharks[i].size<board[tempR][tempC][0]->size){
                        sharks[i].isAlive = false;
                    }
                    else{
                        board[tempR][tempC][0]->isAlive = false;
                        board[tempR][tempC].pop_back();
                        board[tempR][tempC].push_back(&sharks[i]);
                    }
                }
                else{
                    board[tempR][tempC].push_back(&sharks[i]);
                }
            }
        }
        player++;
    }   
    cout<<ret;
    return 0;
}