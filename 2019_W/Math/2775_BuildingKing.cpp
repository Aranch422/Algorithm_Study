#include <iostream>

using namespace std;

int k,n;

void input(){
    cin >> k>>n;
}

int people[15][15];

int main (){
    //0층
    for(int i=0;i<15;i++){
        people[0][i]=i;
        people[i][1]=1;
    }

    //다음층
    for(int i=1;i<15;i++){
        for(int j=2;j<15;j++){
            people[i][j]=people[i][j-1]+people[i-1][j];
        }
    }

    int N;
    cin>>N;
    for (int i=0;i<N;i++){
        input();
        cout<<people[k][n]<<endl;
    }
    return 0;
}