#include <iostream>

using namespace std;

int main(){
    long long A,B,C;

    cin >> A >>B>>C;
    
    long long ans;

    if(B>=C){
        cout<< -1;
        return 0;
    }

    ans = A/(C-B)+1;
    cout << ans;

    return 0;
}