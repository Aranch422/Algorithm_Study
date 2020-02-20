#include <iostream>

using namespace std;

int main(){
    int x[3],y[3];
    for(int i=0;i<3;i++){
        cin>>x[i]>>y[i];
    }
    int x1=x[1]-x[0]; int y1=y[1]-y[0];
    int x2=x[2]-x[1]; int y2=y[2]-y[1];
    int cross=x1*y2-x2*y1;
    int res;
    if(cross>0) res=1;
    else if(cross==0) res=0;
    else res=-1;
    cout<<res;
    return 0;
}