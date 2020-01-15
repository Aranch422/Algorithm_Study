#include <iostream>

using namespace std;

int E,S,M; //15 28 19

void init(){
    cin >>E>>S>>M;
}

int EE=1;
int SS=1;
int MM=1;

int Year;

void solve(){
    for(int y=1;;y++){

        if(E==EE&&S==SS&&M==MM){
            Year=y;
            return;
        }
        
        EE++; SS++; MM++;
        if(EE>15) EE-=15;
        if(SS>28) SS-=28;
        if(MM>19) MM-=19;
    }
}

int main(){
    init();
    solve();
    cout<<Year;
    return 0;
}