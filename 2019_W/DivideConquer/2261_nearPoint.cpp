#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
pair<int,int> point[100000];
pair<int,int> temp[100000];

bool largeX(pair<int,int> a,pair<int,int> b){
    if(a.first<b.first) return true;
    else return false;
}

bool largeY(pair<int,int> a,pair<int,int> b){
    if(a.second<b.second) return true;
    else return false;
}


int dist(pair<int,int> a,pair<int,int> b){
    int x=(a.first-b.first)*(a.first-b.first);
    int y=(a.second-b.second)*(a.second-b.second);
    return (x+y);
}

int minD(int left,int right){
    int minVal=2000000000;
    if(left==right) {
        //cout<<left<<" "<<right<<" MIN"<<endl;
        return minVal;
    }
    int mid=(left+right)/2;
    int shortL = minD(left,mid);
    int shortR = minD(mid+1,right);
    int shorter = min(shortL,shortR);

    minVal=shorter;

    int tempSize=0;
    for(int i=left;i<=right;i++){
        //between shorter 
        int inside = point[mid].first-point[i].first;
        if(inside*inside<minVal){
            temp[tempSize++]=point[i];
        }
    }

    sort(temp,temp+tempSize,largeY);
    for(int i=0;i<tempSize-1;i++){
        for(int j=i+1;j<tempSize;j++){
            int Ygap= temp[j].second - temp[i].second;
            if(Ygap*Ygap>=minVal) break;
            int d=dist(temp[j],temp[i]);
            if(minVal>d) minVal=d;
        }
    }

    //cout<<left<<" "<<right<<" "<<min(shorter,minVal)<<endl;
    return minVal;
}

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        point[i]=make_pair(x,y);
    }
    sort(point,point+n,largeX);
}

void solve(){
    cout<<minD(0,n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    solve();
    /*
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<point[i].first<<" "<<point[i].second<<endl;
    }
    */
    return 0;
}