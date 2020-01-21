#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n>0){
        n--;
        int N;
        cin>>N;

        string s;
        cin>>s;
 
        int size=s.size();
        for(int i=0;i<size;i++){
            for(int k=0;k<N;k++){
                cout<<s[i];
            }
        }
        cout<<"\n";
    }

    return 0;
}