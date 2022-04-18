#include <iostream>
#include <string>

using namespace std;

int fail[1000000];
int m;

void makeFail(string str){
	int cnt=0;
	for(int i=1;i<m;i++){
		if(str[i] == str[cnt]){
			cnt++;
			fail[i] = cnt;
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
	string str;
	cin>>m;
	cin>>str;

	makeFail(str);
	int idx = m-fail[m-1];
	cout<<idx;
	return 0;
}