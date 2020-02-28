#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;

string hear[500000];
string see[500000];

vector<string> ans;

void init(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>hear[i];
    }
    sort(hear,hear+n);
    for(int j=0;j<m;j++){
        cin>>see[j];
    }
    sort(see,see+m);
}

void solve(){
    for(int i=0;i<n;i++){
        int left=0; int right=m-1;
        while(left<=right){
            if(left==right){
                if(hear[i]==see[left]) {
                    ans.push_back(hear[i]);
                    break;
                }
                else break;
            }
            int mid=(left+right)/2;
            if(hear[i]==see[mid]) {
                ans.push_back(hear[i]);
                break;
            }
            else if(hear[i]<see[mid]) right=mid;
            else left=mid+1;
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
    /*
    for(int i=0;i<n;i++){
        cout<<hear[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        cout<<see[i]<<" "; 
    }
    */
}

int main(){
    init();
    solve();
    return 0;
}