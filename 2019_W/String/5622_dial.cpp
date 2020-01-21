#include <iostream>
#include <string>

using namespace std;

int check(char ch){
    if(65<=ch&&ch<68) return 3;
    else if(ch<71) return 4;
    else if(ch<74) return 5;
    else if(ch<77) return 6;
    else if(ch<80) return 7;
    else if(ch<84) return 8;
    else if(ch<87) return 9;
    else if(ch<91) return 10;
}

int main(){
    string s;
    cin>>s;
    int size=s.size();
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=check(s[i]);
    }
    cout<<sum;
}