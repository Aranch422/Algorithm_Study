#include <iostream>
#include <vector>

using namespace std;

vector<int> output;

int N,M;

bool used[9];

void init(){
    cin>>N>>M;
    for(int i=0;i<9;i++){
        used[i] =false;
    }
}

void dfs(int len){
    if(len==0) {
        int size=output.size();
        for(int i=0;i<size;i++){
            cout<<output[i]<<" ";
        }
        cout<<"\n";
        return ;
    }
    for(int i=1;i<=N;i++){
 
        output.push_back(i);
        used[i]=true;
        dfs(len-1);
        used[i]=false;
        output.pop_back();

    }
}

int main(){
    init();
    for(int i=1;i<=N;i++){
        output.push_back(i);
        used[i]=true;
        dfs(M-1);
        used[i]=false;
        output.pop_back();
    }
    return 0;
}