#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
pair<int,int> point[100000];

bool largeX(pair<int,int> a,pair<int,int> b){
    if(a.first<b.first) return true;
    else return false;
}

double dist(pair<int,int> a,pair<int,int> b){
    double x=(a.first-b.first)*(a.first-b.first);
    double y=(a.second-b.second)*(a.second-b.second);
    return (x+y);
}

double minD(int left,int right){
    double minVal=2000000000;
    if(left==right) {
        //cout<<left<<" "<<right<<" MIN"<<endl;
        return minVal;
    }
    int mid=(left+right)/2;
    double shortL = minD(left,mid);
    double shortR = minD(mid+1,right);
    double shorter = min(shortL,shortR);

    minVal=shorter;
    for(int i=mid;i>=left;i--){
        for(int j=mid+1;j<=right;j++){
            pair<int,int> a,b;
            a=point[i]; b=point[j];
            if(b.first-a.first>minVal) break;
            double d = dist(a,b);
            if(minVal>d){
                minVal=d;
            }
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