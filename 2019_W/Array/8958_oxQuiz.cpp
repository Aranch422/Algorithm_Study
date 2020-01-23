#include <iostream>
#include <string>

using namespace std;

int n;

int main(){
    cin>>n;
    while(n>0){
        n--;
        string s;
        cin>>s;
        int size=s.size();
        int score=0;
        int cnt=0;
        for(int i=0;i<size;i++){
            if(s[i]=='O') {
                cnt++;
                score+=cnt;
            }
            else {
                cnt=0;
            }
        }
        cout<<score<<endl;
    }

    return 0;
}