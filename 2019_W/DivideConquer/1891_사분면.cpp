#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int N;

string before;
long long x,y;
long long MAX;

void init(){
    cin >> N;
    MAX = (long long)pow(2,N);
    cin>> before;
    cin>>x>>y;
}

long long xcor(string arr){
    pair<long long,long long> xret;
    xret = make_pair(1,MAX);
    for(int i=0;i<N;i++){
        if(arr[i]=='2'||arr[i]=='3'){
            xret.second = (xret.first + xret.second)/2;
        }
        else{
            xret.first = (xret.first + xret.second)/2+1;
        }
    }

    return xret.first;
}

long long ycor(string arr){
    pair<long long,long long> yret;
    yret = make_pair(1,MAX);
    for(int i=0;i<N;i++){
        if(arr[i]=='3'||arr[i]=='4'){
            yret.second = (yret.first + yret.second)/2;
        }
        else{
            yret.first = (yret.first + yret.second)/2+1;
        }
    }

    return yret.first;
}

int xSearch[50];
int ySearch[50];
int Ans[50];

void binarySearch(long long a,long long b){
    pair<long long,long long> xret;
    xret = make_pair(1,MAX);
    for (int i=0;i<N;i++){
        long long pivot = (xret.first+xret.second)/2;
        if( a<=pivot ){
            xret.second=pivot;
            xSearch[i]=0;
        }
        else {
            xret.first= pivot+1;
            xSearch[i]=1;
        }
    }

    pair<long long,long long> yret;
    yret = make_pair(1,MAX);
    for (int i=0;i<N;i++){
        long long pivot = (yret.first+yret.second)/2;
        if( b<=pivot ){
            yret.second=pivot;
            ySearch[i]=0;
        }
        else {
            yret.first= pivot+1;
            ySearch[i]=1;
        }
    }

    for(int i=0;i<N;i++){
        if(xSearch[i]==1&&ySearch[i]==1) Ans[i]=1;
        else if(xSearch[i]==0&&ySearch[i]==1) Ans[i]=2;
        else if(xSearch[i]==0&&ySearch[i]==0) Ans[i]=3;
        else if(xSearch[i]==1&&ySearch[i]==0) Ans[i]=4;
    }
}

void solve(){
    pair<long long,long long> target;
    target = make_pair(xcor(before)+x,ycor(before)+y);
    if(target.first>MAX||target.second>MAX||target.first<1||target.second<1){
        cout<< -1;
        return;
    }
    binarySearch(target.first,target.second);
    for(int i=0;i<N;i++){
        cout<<Ans[i];
    }
}

int main(){
    init();
    solve();
    return 0;
}