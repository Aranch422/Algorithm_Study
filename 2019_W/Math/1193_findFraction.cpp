#include <iostream>

using namespace std;

int n;

int main(){
    cin>>n;

    int sum;
    int target=2*n;
    for(int k=2;;k++){
        if((k-1)*(k-2)<target && target<=k*(k-1)){
            sum=k;
            break;
        }
    }
    int i = n-(sum-1)*(sum-2)/2;
    if(sum%2==1){
        cout<< i<<"/"<<sum-i;
        return 0;
    }
    else{
        cout<< sum-i<<"/"<<i;
        return 0;
    }
}