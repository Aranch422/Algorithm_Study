#include <iostream>
#include <math.h>

using namespace std;

void hanoi(int n, int from, int to){
    if(n<=0) return;
    int aux=6-from-to;
    hanoi(n-1,from,aux);
    cout<<from<<" "<<to<<"\n";
    hanoi(n-1,aux,to);
}

int main(){
    int N;
    cin>>N;
    int cnt=1;
    for(int i=0;i<N;i++){
        cnt*=2;
    }
    cnt--;
    cout<<cnt<<endl;
    hanoi(N,1,3);
}