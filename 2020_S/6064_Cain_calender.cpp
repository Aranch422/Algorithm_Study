#include <iostream>
#include <vector>

using namespace std;

int n;

int N,M,r1,r2;

int main(){
    cin>>n;
    while(n-->0){
        cin>>N>>M>>r1>>r2;
        vector<int> candidate;
        //if(r1 == N) r1=0;
        if(r2==M) r2=0;

        bool valid =false;
        
        int k=0;
        for(int i=0;k<=N*M;i++){
            k=N*i+r1;
            if(k==0) continue;
            candidate.push_back(k);
        }

        for(int i=0;i<candidate.size();i++){
            if(candidate[i]%M==r2){
                cout<<candidate[i]<<"\n";
                valid=true;
                break;
            }
        }

        if(valid==false){
            cout<<-1<<'\n';
        }
    }

    return 0;
}