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

	while(true){
		cin>>str;
		if(str==".") break;
		m = str.size();
		makeFail(str);
		int idx = -1;
		idx = m - fail[m-1];
		if( idx == m){

		}
		else {
			bool isAnswer = true;
			if(m%idx!=0) {
				isAnswer=false;
			}
			if(isAnswer){
				cout<<m/idx<<endl;
				continue;
			}
		}
		cout<<1<<endl;
	}
	return 0;
}