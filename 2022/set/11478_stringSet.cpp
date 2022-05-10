//trie of KMP will be useful if string size getting bigger
#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> S;

void Insert(string s){
	if(S.find(s) == S.end()){
		S.insert(s);
	}
}

int main(){
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		string temp ="";
		temp += str[i];
		Insert(temp);
		for(int j=i+1;j<str.size();j++){
			temp +=str[j];
			Insert(temp);
		}
	}
	cout<<S.size();
	return 0;
}