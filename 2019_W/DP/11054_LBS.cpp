#include <iostream>

using namespace std;

int n;
int num[1000];
int up[1000];
int down[1000];

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        up[i]=0;
        down[i]=0;
    }

    up[0]=1;
    for(int i=0;i<n;i++){
        int max=0;
        for(int j=i-1;j>=0;j--){
            if(num[i]>num[j]){
                if(max<up[j]) max=up[j];
            }
        }
        up[i]=max+1;
    }

    down[n-1]=1;
    for(int i=n-1;i>=0;i--){
        int max=0;
        for(int j=i+1;j<n;j++){
            if(num[i]>num[j]){
                if(max<down[j]) max=down[j];
            }
        }
        down[i]=max+1;
    }
}

int main(){
    init();
    int max=0;

    for(int i=0;i<n;i++){
        if(max<up[i]+down[i]) max=up[i]+down[i];
        //cout<<up[i]<<" "<<down[i]<<endl;
    }
    cout<<max-1;
    return 0;
}