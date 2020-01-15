#include <iostream>
#include <algorithm>

using namespace std;

int height[9];
int sum=0;

int result[7];
int x1,x2;

void init(){
    for(int i=0;i<9;i++){
        cin>> height[i];
        sum+=height[i];
    }
}

void solve(){
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            if(sum-height[i]-height[j]==100){
                x1=i; x2=j;
                return;
            }
        }
    }
}

int main(){
    init();
    solve();
    int j=0;

    for(int i=0;i<9;i++){
        if(i!=x1&&i!=x2){
            result[j++]=height[i];
        }
    }
    sort(result,result+7);
    for(int i=0;i<7;i++){
        cout << result[i]<<endl;
    }


}
