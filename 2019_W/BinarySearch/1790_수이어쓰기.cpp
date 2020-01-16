#include <iostream>
#include <string>
#include <math.h>

using namespace std;

long long N, target;

void init(){
    cin>> N>>target;
}

void solve(){
    //자리수
    long long temp = target;
    int n=1;

    while(temp>0){
        temp -= 9*pow(10,n-1)*n;
        n++;
    }
    n--;
    temp +=9*pow(10,n-1)*n;
    temp--;

    // n 은 자리수
    int m = temp/n;
    int r = temp%n;

    int tempAns = pow(10,n-1)+m;
    if(tempAns>N) {
        cout <<-1;
        return;
    }    
    string String_Ans= to_string(tempAns);
    int Ans = String_Ans[r]-'0';
    cout << Ans;
}

int main(){
    init();
    solve();
    return 0;
}