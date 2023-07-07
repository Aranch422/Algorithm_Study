#include <iostream>
#include <queue>
#include <string>

using namespace std;

char board[10][10];

struct State{
    int rx,ry,bx,by;
    string nextMove;
    int count;
    State(int rx,int ry, int bx, int by, string nextMove, int count): rx(rx), ry(ry), bx(bx), by(by), nextMove(nextMove), count(count){};
};
queue<State*> myQ;

int w,h;
int rx,ry,bx,by;

bool isRBColide(State state){
    return state.rx==state.bx && state.ry==state.by;
}

void down(State state){
    int rx = state.rx;
    int ry = state.ry;
    int bx = state.bx;
    int by = state.by;

    if(ry<by){
        while(board[by][bx] == '.'){
            by++;
        }
        if(board[by][bx] == '#'){
            by--;
        }
        while(board[ry][rx] == '.'){
            if(isRBColide()){
                break;
            }
            ry++;
        }
        if(board[ry][rx] == '#'){
            ry--;
        }
    }
    else{
        while(board[ry][rx] == '.'){
            ry++;
        }
        if(board[ry][rx] == '#'){
            ry--;
        }
        while(board[by][bx] == '.'){
            if(isRBColide()){
                break;
            }
            by++;
        }
        if(board[by][bx] == '#'){
            by--;
        }
    }
}

int main(){
    cin>>h>>w;
    for(int y=0;i<h;i++){
        for(int x=0;j<w;j++){
            cin>>board[y][x];
            if(board[y][x] == 'R'){
                rx = x;
                ry = y;
                board[y][x] = '.';
            }
            if(board[y][x] == 'B'){
                bx = x;
                by = y;
                board[y][x] = '.';
            }
            }
        }
    }
    
    myQ.push(new State(rx,ry,bx,by,"Down",1));
    myQ.push(new State(rx,ry,bx,by,"Up",1));
    myQ.push(new State(rx,ry,bx,by,"Left",1));
    myQ.push(new State(rx,ry,bx,by,"Right",1));
    return 0;
}