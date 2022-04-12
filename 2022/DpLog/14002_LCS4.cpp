#include <iostream>
#include <string>

using namespace std;

int num[1000];
int len[1000];
string Log[1000];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
		Log[i] = to_string(num[i]);
		len[i] =1;
	}
	for(int i=n-2;i>=0;i--){
		string tempLog;
		int maxLen = 0;
		for(int j=i+1;j<n;j++){
			if(num[j]>num[i]){
				if(maxLen<len[j]){
					maxLen = len[j];
					tempLog = " "+Log[j];	
				}
			}
		}
		len[i] = maxLen+1;
		Log[i] += tempLog;
	}
	int loc;
	int maximum = -1;
	for(int i=0;i<n;i++){
		if(maximum<len[i]){
			maximum = len[i];
			loc = i;
		}
	}
	cout<<len[loc]<<endl;
	cout<<Log[loc];
	
	return 0;
}