#include <iostream>

using namespace std;;

int main(){
    int h,m;
    cin>>h>>m;
    if(m-45<0) {
        m=m+15;
        if(h-1<0){
            h=23;
        }
        else{
            h--;
        }
    }
    else{
        m=m-45;
    }
    cout<<h<<" "<<m;
    return 0;
}