#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> mys;

int main(){
    cin>>n;
    while(n>0){
        n--;
        int a;
        cin>>a;
        if(a!=0){
            mys.push(a);
        }
        else mys.pop();
    }
    int sum=0;
    if(mys.size()!=0) {
        int size= mys.size();
        for(int i=0;i<size;i++){
            sum+=mys.top();
            mys.pop();
        }
    }
    cout<<sum;
    return 0;
}