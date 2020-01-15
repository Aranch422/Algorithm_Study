#include <iostream>
#include <cstring>

using namespace std;

int N;
int A[1000];

void init(){
    cin>>N;
    memset(A,-1,sizeof(A));
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

}

int result=0;

void solve(){
    int dist=N-1;
    int now=0;
    while(dist>0){
        //넘어가면
        if(dist-A[now]<=0){
            result++;
            return;
        }

        //갇히면
        if(A[now]==0) {
            result=-1;
            return;
        }
        
        else{
            int temp=-1;
            int tempI=0;
            //제일 멀리 갈 수 있는걸 고름
            for(int i=1;i<=A[now];i++){
                if(now+i+A[now+i]>temp) {
                    temp=now+i+A[now+i];
                    tempI=i;
                }
            }
            now=now+tempI;
            dist-=tempI;
            result++;
        }
    }
}

int main(){
    init();
    solve();

    cout<<result;


    return 0;
}