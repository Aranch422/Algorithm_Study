#include <iostream>
#include <string>

using namespace std;

string s;
int cnt[200];

void init(){
    cin>>s;
    for(int i=0;i<200;i++){
        cnt[i]=0;
    }
}

int main(){
    init();
    int size=s.size();
    for(int i=0;i<size;i++){
        if(int(s[i])>=97){
            cnt[int(s[i])-32]++;
        }
        else{
            cnt[int(s[i])]++;
        }
    }
    char ret;
    int max=0;
    for(int i=65;i<91;i++){
        if(cnt[i]>max) {
            max=cnt[i];
            ret=char(i);
        }    
    }
    for(int i=65;i<97;i++){
        if(cnt[i]==max&&char(i)!=ret) ret='?';
    }
    cout<<ret;
    return 0;
}