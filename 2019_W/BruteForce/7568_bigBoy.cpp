#include <iostream>

using namespace std;

pair<int,int> ppl[50];
int bigger[50];
int N;
int myrank[50];

void init(){
    cin>>N;
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        ppl[i]=make_pair(x,y);
        bigger[i]=1;
        myrank[i]=1;
    }
}

void solve(){
    //how many people bigger than me
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) continue;
            if(ppl[i].first<ppl[j].first&&ppl[i].second<ppl[j].second){
                bigger[i]++;
            }
        }
    }

    //my rank
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) continue;
            if(bigger[i]>bigger[j]) myrank[i]++;
        }
    }
}

int main(){
    init();
    solve();
    for(int i=0;i<N;i++){
        cout<<bigger[i]<<" ";
    }

    return 0;
}