#include<iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> a = vector<int>(5);
    for(auto item : a){
        cout<<item;
    }
    cout<<endl;
    vector<int> b = a;
    a[0]= 1;
    for(auto item : a){
        cout<<item;
    }
    for(auto item : b){
        cout<<item;
    }
    return 0;
}