#include <iostream>

using namespace std;

double sum=0;
int n;
int num[1000];
double Max=0;

void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        sum+=num[i];
        if(Max<num[i]) Max=num[i];
    }
}

int main(){
    cout.setf(ios::fixed);
    cout.precision(3);
    init();
    cout<<sum/Max*100/n;

    return 0;
}