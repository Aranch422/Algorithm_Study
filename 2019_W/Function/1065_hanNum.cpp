#include <iostream>

using namespace std;

int num[1001][4];

void init(){
    for(int i=1;i<=1000;i++){
        for(int j=0;j<4;j++){
            num[i][j]=-1;
        }
        int temp=i;
        for(int k=0;temp>0;temp=temp/10){
            num[i][k++]=temp%10;

        }
    }
}


int main(){
    init();
    int cnt=0;
    int dif;
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        bool flag=true;
        //1
        if(num[i][1]==-1) flag=true;
        else {
            dif=num[i][1]-num[i][0];
            //2
            if(num[i][2]==-1) flag =true;
            //3 4
            for(int j=1;j<4;j++){
                if(j<3&&num[i][j+1]!=-1){
                    if(num[i][j+1]-num[i][j]!=dif) flag=false;
                }
            }
        }
        if(flag) cnt++;
    }
    cout<<cnt;
    return 0;
}