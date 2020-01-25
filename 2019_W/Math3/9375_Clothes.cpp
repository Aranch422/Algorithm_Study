#include <iostream>
#include <string>

using namespace std;

int n;
int Size=0;
pair<int,string> myL[30]; 

void init(){
    cin>>n;
    Size=0;
    for(int i=0;i<n;i++){
        bool newType=true;
        string name, type;
        cin>>name>>type;
        for(int j=0;j<Size;j++){
            if(myL[j].second==type) {
                //cout<<"not new"<<name<<j<<" ";
                myL[j].first++;
                newType=false;
                break;
            }
        }
        if(newType){
            //cout<<"new"<<name<<Size<<" ";
            myL[Size]=make_pair(1,type);
            Size++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int nn;
    cin>>nn;
    while(nn>0){
        nn--;
        int mul=1;
        init();
        for(int i=0;i<Size;i++){
            //cout<<myL[i].first<<" ";
            mul*=(myL[i].first+1);
        }
        mul--;
        cout<<mul<<"\n";
    }
    return 0;
}