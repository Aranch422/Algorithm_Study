#include <iostream>

using namespace std;

int N,M;

int num[100];

void init(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
}

int main(){
    init();
    int max=-1;
    for(int i=0;i<N-2;i++){
        for(int j=i+1;j<N-1;j++){
            for(int k=j+1;k<N;k++){
                int sum=num[i]+num[j]+num[k];
                if(sum<=M&&max<sum){
                    max=sum;
                }
            }
        }
    }
    cout<<max;

    return 0;
}