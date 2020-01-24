#include <iostream>
#include <string>

using namespace std;
string a,b;
int sizeA,sizeB;

// bbbbbb
//a
//a
int ab[1001][1001];

void init(){
    cin>>a>>b;
    sizeA=a.size();
    sizeB=b.size();
}

void solve(){
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            ab[i][j];
        }
    }
    for(int i=1;i<=sizeA;i++){
        for(int j=1;j<=sizeB;j++){
            if(a[i-1]==b[j-1]) ab[i][j]=ab[i-1][j-1]+1;
            else{
                if(ab[i-1][j]>ab[i][j-1]) ab[i][j]=ab[i-1][j];
                else ab[i][j]=ab[i][j-1];
            }
            
        }
    }
    cout<<ab[sizeA][sizeB];
}

int main(){
    init();
    solve();
    
    /*
    cout<<endl;
    for(int i=0;i<=sizeA;i++){
        for(int j=0;j<=sizeB;j++){
            cout<<ab[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    

    return 0;
}