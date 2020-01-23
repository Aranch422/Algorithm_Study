#include <iostream>

using namespace std;

int N,n;
int num[1000];

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }

}

void solve(){
    int sum=0;
    int mean=0;
    for(int i=0;i<n;i++){
        sum+=num[i];
    }
    mean=sum/n;
    double cnt=0;
    for(int i=0;i<n;i++){
        if(mean<num[i]) cnt++;  
    }
    cout<<cnt/n*100<<"%\n";
}


int main(){
    cout.setf(ios::fixed);
    cout.precision(3);
    cin>>N;
    for(int i=0;i<N;i++){
        init();
        solve();
    }
    return 0;
}