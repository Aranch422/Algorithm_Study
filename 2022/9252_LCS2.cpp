#include <iostream>
#include <string>

using namespace std;

bool isExist[1000][26];

int main(){
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<s2.size();i++){
		for(int j=0;j<26;j++) isExist[i][j]=false;
	}
	for(int i=0;i<s2.size();i++){
		for(int j=i-1;j>=0;j--){
			isExist[j][int(s2[i])-65]=true;
		}
	}	
	int maxLen = 0;
	string Log = "";
	for(int i=0;i<s1.size();i++){
		int num = int(s1[i])-65;
		int len;
		string temp;
		for(int j=0;j<s2.size();j++){
			if(isExist[j][num]){
				len=0;
				temp="";
				len++;
				temp+=s1[i];
				for(int k=i+1;k<s1.size();k++){
					
					if(isExist[j][int(s1[k])-65]){
						cout<<k<<" "<<s1[k]<<endl;
						len++;
						temp+=s1[k];
					}
				}
			}
			if(maxLen<len){
				maxLen = len;
				Log = temp;
			}
		}
	}
	cout<<Log;
	cout<<endl;
	for(int i=0;i<s2.size();i++){
		for(int j=0;j<26;j++){
			cout<<isExist[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 