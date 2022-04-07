#include <iostream>

using namespace std;

int dp[501];

int main(){
	int T=0;
	int n,m;
	while(true){
		T++;
		cin>>n>>m;
		for(int i=1;i<=n;i++) dp[i] =0;
		
		int count = 0;
		int answer =0;
		if(n==0&& m==0) break;
		for(int j=0;j<m;j++){
			int start,end;
			cin>>start>>end;
			if(start == end){
				if(dp[start]==0) dp[start] = -1;
				else if(dp[start]==-1){
					
				}
				else{
					answer--;
					int temp = dp[start];
					for(int i=1;i<=n;i++){
						if(dp[i]==temp) dp[i]=-1;
					}
				}
				continue;
			}
			if(dp[start]==-1){
				if(dp[end]==0) dp[end]=-1;
				else if(dp[end]==-1){
					
				}
				else{
					int temp = dp[end];
					for(int i=1;i<=n;i++){
						if(dp[i] == temp) dp[i] = -1;
					}
					answer--;
				}
			}
			else if(dp[start]==0) {
				if(dp[end]==-1) dp[start]=-1;
				else if(dp[end]==0){
					dp[start]=++count;
					dp[end] = count;
					answer++;
				}
				else{
					dp[start]=dp[end];
				}
			}
			else{
				if(dp[end]==-1) {
					int temp = dp[start];
					for(int i=1;i<=n;i++){
						if(dp[i]==temp) dp[i] = -1;
					}
					answer--;
				}
				else if(dp[end]==0){
					dp[end] = dp[start];
				}
				else{
					if(dp[start]==dp[end]){
						int temp = dp[start];
						for(int i=1;i<=n;i++){
							if(dp[i]==temp) dp[i]=-1;
						}
						answer--;
					}
					else{
						int temp = dp[start];
						for(int i=1;i<=n;i++){
							if(dp[i]==temp) dp[i]=dp[end];
						}
						answer--;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(dp[i]==0) answer++;
		}
		//if(T!=1) cout<<"\n"; 
		cout<<"Case "<<T<<": ";
		if(answer==0) cout<<"No trees.\n";
		else if(answer==1) cout<<"There is one tree.\n";
		else{
			cout<<"A forest of "<<answer<<" trees.\n";
		}
	}
	
	return 0;
}