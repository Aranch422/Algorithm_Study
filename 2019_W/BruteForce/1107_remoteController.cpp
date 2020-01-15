#include <iostream>
#include <stdlib.h>

using namespace std;

int N;
bool able[10]={true,true,true,true,true,true,true,true,true,true};

void init(){
    cin >> N;
    int n;
    cin >> n;
    int num;
    for (int i=0;i<n;i++){
        cin >>num;
        able[num]=false;
    }
}

bool check(int n){
    while (n>0){
        int rem = n%10;
        if(able[rem]){
            n=n/10;
        }
        else return false;
    }
    return true;
}

int digit(int n){
    int d=0;
    while(n>0){
        n=n/10;
        d++;
    }
    return d;
}

int solve(){
    int ret;

    if(check(N)){
        ret =digit(N);
        if(ret<abs(N-100)) return ret;
        else return abs(N-100);
    }

    int Nl=N;
    int Ns=N;

    int retL=500000;
    int retS=500000;
    while(1){
        Ns--;
        if(Ns<0){
            break;
        }
        if(check(Ns)){
            retS = digit(Ns)+N-Ns;
            break;
        }
    }

    while(Nl-N<500000){
        Nl++;
        if( check(Nl)){
            retL= digit(Nl)+Nl-N;
            break;
        }

    }
    ret = (retL<retS? retL:retS);
    if(ret<abs(N-100)) return ret;
    else return abs(N-100);
}
int main(){
    init();
    cout<<solve();
    return 0;
}