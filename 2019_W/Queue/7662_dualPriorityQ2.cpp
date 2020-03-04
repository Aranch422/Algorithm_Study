#include <iostream>
#include <queue>
#include <vector>

using namespace std;


void solve(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Min;
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> Max;
    
    int idx=0;
    vector<bool> isDeleted;
    int n;
    cin>>n;
    while(n>0){
        n--;
        string s;
        cin>>s;
        if(s=="I"){
            int num;
            cin>>num;
            Max.push(make_pair(num,idx));
            Min.push(make_pair(num,idx));
            idx++;
            isDeleted.push_back(false);
        }
        if(s=="D"){
            int num;
            cin>>num;
            if(Max.empty()||Min.empty()) continue;
            //del Max
            if(num==1){
                while(!Max.empty()&&isDeleted[Max.top().second]){
                    Max.pop();
                }
                if(!Max.empty()){
                    isDeleted[Max.top().second]=true;
                    Max.pop();
                }
            }

            if(num==-1){
                while(!Min.empty()&&isDeleted[Min.top().second]){
                    Min.pop();
                }
                if(!Min.empty()){
                    isDeleted[Min.top().second]=true;
                    Min.pop();
                }
            }
        }
    }
    while(!Max.empty()&&isDeleted[Max.top().second]){
        Max.pop();
    }
    while(!Min.empty()&&isDeleted[Min.top().second]){
        Min.pop();
    }
    if(Max.empty()||Min.empty()) cout<<"EMPTY\n";
    else{
        cout<<Max.top().first<<" "<<Min.top().first<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin>>k;
    while(k>0){
        k--;
        solve();
    }
    return 0;
}