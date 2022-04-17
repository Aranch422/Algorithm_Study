#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fail[1000000];

int n,m;

void makeFail(string str){
	int cnt = 0;
	for(int i=1;i<m;i++){
		if(str[cnt] == str[i]){
			fail[i] = ++cnt;
		}
		else{
			while(str[i]!=str[cnt] && cnt!=0){
				cnt = fail[cnt-1];
			}
			if(str[i] == str[cnt]){
				cnt++;
			}
			fail[i] = cnt;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string T;
	string P;
	
	getline(cin,T);
	getline(cin,P);
	m = P.size();

	makeFail(P);
	
	n = T.size();
	int j = 0;
	int ans = 0;
	vector<int> Log;
	for(int i=0;i<n;i++){
		if( j == m ){
			ans++;
			Log.push_back(i-m+1); //starts with 1
			j = fail[j-1];
			while(T[i]!=P[j] && j!=0){
				j = fail[j-1];
			}
			if(T[i] == P[j]){
				j++;
			}
			else if(j == 0){
				if(T[i]==P[j]){
					j++;
				}
			}
		}
		else if(T[i] == P[j]){
			j++;
		}
		else{
			while(T[i]!=P[j] && j!=0){
				j = fail[j-1];
			}
			if(T[i] == P[j]){
				j++;
			}
			else if(j == 0){
				if(T[i]==P[j]){
					j++;
				}
			}
		}
	}
	if(j==m){
		ans++;
		Log.push_back(n-m+1);
	}
	cout<< ans<<endl;
	for(int i=0;i<Log.size();i++){
		cout<<Log[i]<<" ";
	}
	return 0;
}