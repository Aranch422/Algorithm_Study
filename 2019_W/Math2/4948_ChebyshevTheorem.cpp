#include <iostream>
#include <math.h>

using namespace std;

int N;
bool num[1234561];

void init(){
    for(int i=0;i<1234561;i++){
        num[i]=true;
    }
    num[0]=false;
    num[1]=false;
}

int main(){
    while(1){
        cin>>N;
        if(N==0) return 0;
        int cnt=0;
        init();
        for(int i=2;i<=sqrt(2*N);i++){
            for(int j=i*i;j<=2*N;j+=i){
                num[j]=false;
            }
        }

        for(int i=N+1;i<=2*N;i++){
            if(num[i]) cnt++;
        }
        cout<<cnt<<endl;
    }

}