#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;

int num[500000];
int cnt[8001];

void init(){
    cin>>n;

    for(int i=0;i<8001;i++){
        cnt[i]=0;
    }

    for(int i=0;i<n;i++){
        cin>>num[i];
        cnt[num[i]+4000]++;
    }
}

void solve(){
    int sum=0;
    sort(num,num+n);
    for(int i=0;i<n;i++){
        sum+=num[i];
    }

    int cntMax=0;
    for(int i=0;i<8001;i++){
        if(cnt[i]>cntMax) cntMax=cnt[i];
    }

    vector<int> temp;

    for(int i=0;i<8001;i++){
        if(cnt[i]==cntMax){
            temp.push_back(i-4000);
        }
    }



    //mean
    double mean = sum;
    mean=mean/n;
    cout<<round(mean)<<"\n";
    //median
    cout<<num[n/2]<<"\n";
    //
    int size= temp.size();
    if(size==1) cout<< temp[0]<<"\n";
    else{
        cout<<temp[1]<<"\n";
    }

    //range
    cout<<num[n-1]-num[0];
}

int main(){
    init();
    solve();

    return 0;
}