#include <iostream>

using namespace std;

void solve(int a,int b,int c){
    int max=a;
    if(a<b) max=b;
    if(max<c) max =c;
    if(max*max==a*a+b*b) cout<<"right"<<endl;
    else if(max*max==b*b+c*c) cout<<"right"<<endl;
    else if(max*max==a*a+c*c) cout<<"right"<<endl;
    else cout<< "wrong"<<endl;
}

int main(){
    int a,b,c;
    while(1){
        cin>>a>>b>>c;
        if(a==0) return 0;
        solve(a,b,c);
    }

}