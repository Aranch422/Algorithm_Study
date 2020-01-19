#include <iostream>
#include <string>

using namespace std;

int N;

string myPrint(int n,int part){



    if(part==0){
        if(n==1) return " ";
        else{
            return myPrint(n/3,0)+myPrint(n/3,0)+myPrint(n/3,0);
        }
    }

    if(part==1||part==3){
        if(n==1) return "*";
        if(n==3) return "***";
        return myPrint(n/3,1)+myPrint(n/3,1)+myPrint(n/3,1)+
        myPrint(n/3,2)+myPrint(n/3,2)+myPrint(n/3,2)+
        myPrint(n/3,3)+myPrint(n/3,3)+myPrint(n/3,3);
    }
    if(part==2){
        if(n==1) return "*";
        if(n==3) return"* *";
        return myPrint(n/3,1)+myPrint(n/3,0)+myPrint(n/3,1)+
        myPrint(n/3,2)+myPrint(n/3,0)+myPrint(n/3,2)+
        myPrint(n/3,3)+myPrint(n/3,0)+myPrint(n/3,3);
    }
}

void myPrint(int n){
    cout<<myPrint(n,1)<<endl;
    cout<<myPrint(n,2)<<endl;
    cout<<myPrint(n,3)<<endl;
}

int main(){
    cin>>N;
    myPrint(N);
    return 0;
}