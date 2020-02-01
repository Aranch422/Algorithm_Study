#include <iostream>

using namespace std;

int n;
int num[1000000];
int dp[1000000];

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    dp[0]=1;
    int left,right;
    for(int i=1;i<n;i++){
        left=0; right=i-1;
        int dpmax=0;
        while(left!=right){
            int mid=(left+right)/2;
            if(dpmax<=dp[mid]){
                if(dp[mid]<dp[i]){
                    dpmax=dp[mid];
                }
                
            }
            else{
                if(dp[mid]<dp[i]);
            }
        }
        //left==right 해주고
        
        dp[i]=dpmax;
    }
}

int main(){

    return 0;
}