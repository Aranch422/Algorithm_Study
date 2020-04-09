#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int list[5];
    for(int i=0;i<5;i++){
        cin>>list[i];
    }
    sort(list,list+3);
    sort(list+3,list+5);
    cout<<list[0]+list[3]-50;
    return 0;
}