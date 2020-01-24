#include <iostream>
#include <queue>

using namespace std;

int n,a,b;
int list[10];

queue<pair<bool,int>> Q;

void init(){
    cin>>a>>b;
    for(int i=0;i<10;i++){
        list[i]=0;
    }

    for(int i=0;i<a;i++){
        int num;
        cin>>num;
        list[num]++;
        if(i==b){
            Q.push(make_pair(true,num));
        }
        else Q.push(make_pair(false,num));
    }
}

int solve(){
    int Max;
    for(int i=9;i>0;i--){
        if(list[i]!=0) {
            Max=i;
            break;
        }
    }
    int cnt=1;
    while(Q.size()>0){
        pair<bool,int> temp;
        temp=Q.front();
        if(temp.second==Max){
            if(temp.first) return cnt;
            else{
                Q.pop();
                cnt++;
                list[Max]--;
            }
        }
        else{
            Q.pop();
            Q.push(temp);
        }
        if(list[Max]==0){
            for(int i=Max-1;i>0;i--){
                if(list[i]!=0) {
                    Max=i;
                    break;
                }
            }
        }
    }
    
}


int main(){
    cin>>n;
    while(n){
        int size=Q.size();
        while(!Q.empty()){
            Q.pop();
        }
        n--;
        init();
        cout<<solve()<<endl;
    }
}