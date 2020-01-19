#include <iostream>

using namespace std;

int gen(int i){
    int ret=i;
    while(i>0){
        ret+=i%10;
        i=i/10;
    }
    return ret;
}

int main(){
    int n;
    int min=0;
    cin>>n;
    for(int i=1;i<n;i++){
        if(gen(i)==n) {
            min=i;
            break;
        }
    }
    cout<< min;
    return 0;
}