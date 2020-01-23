#include <iostream>
#include <algorithm>

using namespace std;

int n; int k;
pair<int,int> thing[100];
int dp[100];

bool check(pair<int,int> a,pair<int ,int>b){
    if(a.first<b.first) return true;
    else return false;
}


void init(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        thing[i]=make_pair(a,b);
    }
    sort(thing,thing+100,check);

    for(int i=0;i<n;i++){
        
    }

}

int main(){


    return 0;
}