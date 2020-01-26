#include <iostream>

using namespace std;

int n,m;

void init(){
    cin>>n>>m;
}

pair<int,int> solveN(){
    int ret2=0;
    int ret5=0;

    for(int i=2;i<=n;i*=2){
        ret2+=m/i;

        if(m%i>=n%i) ret2++;

    }
    for(int i=5;i<=n;i*=5){
        ret5+=m/i;
        if(m%i>n%i) ret5++;

        
    }
    return make_pair(ret2,ret5);
}

pair<int,int> solveM(){
    int ret2=0;
    int ret5=0;
    for(int i=2;i<=m;i*=2){
        ret2+=m/i;
    }
    for(int i=5;i<m;i*=5){
        ret5+=m/i;
    }
    return make_pair(ret2,ret5);
}

int main(){
    init();
    pair<int,int> N,M,Ans;

    N=solveN();
    //cout<<N.first<<" "<<N.second<<endl;
    M=solveM();
    //cout<<M.first<<" "<<M.second<<endl;

    Ans=make_pair(N.first-M.first,N.second-M.second);
    if(Ans.first>Ans.second) cout<<Ans.second;
    else cout<<Ans.first;
    return 0;
}