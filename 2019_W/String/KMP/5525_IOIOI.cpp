#include <iostream>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int res=0;

    int n,len;
    string s;
    cin>>n>>len>>s;

    for(int i=0;i<len;i++){
        if(s[i+1]=='O'&&s[i+2]=='I'){
            int Ocount=0;
            while(s[i]=='I'&&s[i+1]=='O'){
                Ocount++;
                i=i+2;
                if(s[i]=='I'&&Ocount==n){
                    res++;
                    Ocount--;
                }
            }
        }
    }
    cout<<res;
    return 0;
}

