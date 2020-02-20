#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string pok[100001];
pair<string,int> BSA[100001];

bool check(pair<string,int> a,pair<string,int> b){
    return a.first<b.first;
}

void BS(int left,int right,string target){
    if(left==right){
        cout<<BSA[left].second<<"\n";
        return;
    }
    int mid=(left+right)/2;
    if(BSA[mid].first<target){
        BS(mid+1,right,target);
    }
    else{
        BS(left,mid,target);
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>pok[i];
        BSA[i]=make_pair(pok[i],i);
    }
    sort(BSA+1,BSA+n+1,check);

    for(int i=0;i<k;i++){
        string name;
        cin>>name;
        int ncheck=name[0]-48;
        if(0<=ncheck&&ncheck<=9){
            int num=stoi(name);
            cout<<pok[num]<<'\n';
        }
        else{
            BS(1,n,name);
        }
    }
    /*
    for(int i=1;i<=n;i++){
        cout<<BSA[i].first<<" "<<BSA[i].second<<"\n";
    }
    */
    return 0;
}