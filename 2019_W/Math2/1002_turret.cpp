#include <iostream>
#include <math.h>

using namespace std;

int distSquare(int x1,int y1,int x2,int y2){
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

int main(){
    int n;
    int x1,y1,x2,y2;
    int r1,r2;
    cin >>n;
    while(n>0){
        n--;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        //1
        if(x1==x2&&y1==y2){
            if(r1==r2){
                cout<< -1<<endl;
                continue;
            }
            else{
                cout<<0<<endl;
            }
        } 
        
        else{
            //2
            if(distSquare(x1,y1,x2,y2)<(r1-r2)*(r1-r2)) cout<<0<<endl;
            //3
            else if(distSquare(x1,y1,x2,y2)==(r1-r2)*(r1-r2)) cout<<1<<endl;
            //4
            else if(distSquare(x1,y1,x2,y2)>(r1-r2)*(r1-r2)&&distSquare(x1,y1,x2,y2)<(r1+r2)*(r1+r2)) cout<<2<<endl;
            //5
            else if(distSquare(x1,y1,x2,y2)==(r1+r2)*(r1+r2)) cout << 1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}