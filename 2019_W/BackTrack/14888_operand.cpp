#include <iostream>
#include <vector>
#include <string>

using namespace std;

int num[11];

//0 +  1-  2*  3/
int op[4];
int n;
int Max=-1000000001;
int Min=1000000001;

string s;
vector<string> vec;

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<4;i++){
        cin>>op[i];
    }
}

int cnt=0;

void pick(int level){
    if(level==0){
        cnt++;
        vec.push_back(s);
        return;
    }
    for(int i=0;i<4;i++){
        if(op[i]!=0){
            op[i]--;
            s=s+to_string(i);
            pick(level-1);
            s.pop_back();
            op[i]++;
        }
    }
}

int cal(string mys){
    int sum=num[0];
    for(int i=0;i<n-1;i++){
        if(mys[i]=='0'){
            sum+=num[i+1];
        }
        else if(mys[i]=='1'){
            sum-=num[i+1];
        }
        else if(mys[i]=='2'){
            sum*=num[i+1];
        }
        else if(mys[i]=='3'){
            sum/=num[i+1];
        }
    }
    return sum;
}

void solve(){
    int size =vec.size();
    for(int i=0;i<size;i++){
        int value =cal(vec[i]);
        if(value>Max) Max=value;
        if(value<Min) Min=value;
    }
}

int main(){
    init();
    pick(n-1);
    solve();
    cout<<Max<<"\n"<<Min;
    return 0;
}