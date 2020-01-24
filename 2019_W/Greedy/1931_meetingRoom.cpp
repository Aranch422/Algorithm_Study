#include <iostream>
#include <algorithm>

using namespace std;

int n;
int cnt=0;

// first start second end
pair<int,int> list[100001];

bool endEarly(pair<int,int> a,pair<int,int> b){
    if(a.second<b.second) return true;
    else if(a.second==b.second){
        if(a.first<b.first) return true;
        else return false;
    }
    else return false;
}

void init(){
    cin>>n;
    list[0]=make_pair(0,0);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        list[i+1]=make_pair(a,b);
    }
    sort(list,list+n+1,endEarly);
}

void solve(int idx){
    //cout<<list[idx].second<<" ";
    for(int i=idx+1;i<=n;i++){
        if(list[i].first>=list[idx].second) {
            //cout<<list[i].first<<endl;
            cnt++;
            solve(i);
            break;
        }
    }
    return;
}

int main(){
    init();
    solve(0);
    cout<<cnt<<endl;
    /*
    for(int i=1;i<=n;i++){
        cout<<list[i].first<<" "<<list[i].second<<endl;
    }
    */
    return 0;
}