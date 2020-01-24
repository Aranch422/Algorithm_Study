#include <iostream>
#include <string>

using namespace std;

string s;
int num[50];
int idx=0;
int cnt=0;

void init(){
    cin>>s;
    string temp;
    int size=s.size();
    int start;
    start=0;
    for(int i=0;i<size;i++){
        if(s[i]=='-'||s[i]=='+') {
            num[idx++]=stoi(temp);
            temp="";
            continue;
        }
        temp+=s[i];
        if(i==size-1) num[idx++]=stoi(temp);
    }

    for(int i=0;i<size;i++){
        if(s[i]=='+') cnt++;
        if(s[i]=='-') break;
    }
}

int main(){
    init();
    
    /*
    for(int i=0;i<idx;i++){
        cout<<num[i]<<" ";
    }
    */

    int sum=num[0];
    for(int i=1;i<=cnt;i++){
        sum+=num[i];
    }
    for(int i=cnt+1;i<idx;i++){
        sum-=num[i];
    }
    cout<<sum;
    return 0;
}