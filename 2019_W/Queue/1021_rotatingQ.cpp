#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int n,k;
deque<int> D;

void init(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        D.push_back(i);
    }
}

void solve(){
    int target;
    int cnt=0;
    for(int i=0;i<k;i++){
        int tempcnt=0;
        cin>>target;
        //match then pop
        if(D.front()==target) D.pop_front();
        else{
            while(D.front()!=target){
                int temp=D.front();
                D.pop_front();
                D.push_back(temp);
                tempcnt++;
            }
            if(tempcnt>D.size()/2) cnt+=D.size()-tempcnt;
            else cnt+=tempcnt;
            D.pop_front();
        }
    }
    cout<<cnt;
}


int main(){
    init();
    solve();

    return 0;
}