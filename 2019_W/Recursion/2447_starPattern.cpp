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

string myPrint(int n){
    return myPrint(n,1)+myPrint(n,2)+myPrint(n,3);
}

int main(){
    cin>>N;
    string ret=myPrint(N);
    cout<< ret.size()<<endl;
    for(int i=0;i<ret.size();i++){
        cout<<ret[i];
        if(i%N==N-1) cout<<"\n";
    }
    return 0;
}