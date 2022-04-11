#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[1001][1001];

int main(){
	string str1, str2;
	int size=0;
	cin>>str1>>str2;
	for(int i=0;i<=str1.size();i++){
		for(int j=0;j<=str2.size();j++){
			dp[i][j]=0;
		}
	}
	
	for(int i=0;i<str1.size();i++){
		for(int j=0;j<str2.size();j++){
			if(str1[i]==str2[j]){
				dp[i+1][j+1] = dp[i][j]+1;
			}
			else{
				dp[i+1][j+1] = (dp[i+1][j]>dp[i][j+1])? dp[i+1][j]:dp[i][j+1];
			}
		}
	}
	cout<<dp[str1.size()][str2.size()]<<endl;
	int now = dp[str1.size()][str2.size()];
	int i=str1.size();
	int j=str2.size();
	
	vector<char> ans;
	
	while(dp[i][j]!=0){
		if(i==0 || j == 0 ) break;
		now = dp[i][j];
		if(str1[i-1] == str2[j-1]){
			ans.push_back(str1[i-1]);
			i--;
			j--;
		}
		else{
			if(dp[i][j-1] == now) j--;
			else if(dp[i-1][j] == now) i--;
		}
	}
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
}
