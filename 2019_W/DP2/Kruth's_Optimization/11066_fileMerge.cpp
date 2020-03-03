#include <iostream>

using namespace std;

void init(){
    int nn;
    cin>>nn;
    
    //init with 0
    int pageSum[501]={};
    int cost[501][501]={};
    int Kruth[501][501]={};

    //setting
    for(int i=1;i<=nn;i++){
        int page;
        cin>>page;
        pageSum[i]=pageSum[i-1]+page;
        if(i==1) continue;
        cost[i-1][i]=pageSum[i]-pageSum[i-2];
        Kruth[i-1][i]=i-1;
    }
    
    //solve
    for(int gap=2;gap<=nn-1;gap++){
        for(int i=1;i<=nn;i++){
            int j=i+gap;
            if(j>nn) break;
            int MIN=987654321;
            int tempCost,tempK;
            for(int k=Kruth[i][j-1];k<=Kruth[i+1][j];k++){
                tempCost=cost[i][k]+cost[k+1][j]+pageSum[j]-pageSum[i-1];
                if(tempCost<MIN) {
                    MIN=tempCost;
                    tempK=k;
                }
            }
            //cout<<i<<" "<<j<<" "<<tempCost<<" "<<tempK<<endl;
            //cout<<cost[i][tempK]<<" "<<cost[tempK+1][j]<<" "<<pageSum[j]<<" "<<pageSum[i-1]<<endl;
            cost[i][j]=MIN;
            Kruth[i][j]=tempK;
        }
    }
    /*
    for(int i=1;i<=nn;i++){
        for(int j=1;j<=nn;j++){
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=nn;i++){
        for(int j=1;j<=nn;j++){
            cout<<Kruth[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<=nn;i++){
        cout<<pageSum[i]<<" ";
    }
    cout<<endl;
    */
    cout<<cost[1][nn]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    while(n>0){
        n--;
        init();

    }
    return 0;
}