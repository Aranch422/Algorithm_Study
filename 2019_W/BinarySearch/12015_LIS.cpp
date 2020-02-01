#include <iostream>
#include <vector>

using namespace std;

int n;
int num[1000000];
vector<int> Lis;

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
}

void solve(){
    for(int i=0;i<n;i++){
        if(Lis.size()==0){
            Lis.push_back(num[i]);
        }
        else if(Lis.back()<num[i]){
            Lis.push_back(num[i]);
        }
        else{
            int left=0;
            int right=Lis.size()-1;
            while(left<right){
                int mid=(left+right)/2;
                if(Lis[mid]<num[i]){
                    left=mid+1;
                }
                else right=mid;
            }
            Lis[left]=num[i];
        }
        /*
        for(int i=0;i<Lis.size();i++){
            cout<<Lis[i]<<" ";
        }
        cout<<endl;
        */
    }
    cout<<Lis.size();
}

int main(){
    init();
    solve();
    return 0;
}