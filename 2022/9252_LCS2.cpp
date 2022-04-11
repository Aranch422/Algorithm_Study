#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string str1, str2;
	int size=0;
	string ans = "";
	cin>>str1>>str2;
	for(int i=0;i<str1.size();i++){
		for(int j=0;j<str2.size();j++){
			if(str1[i] == str2[j]){
				int tempSize = 1;
				string tempStr = "";
				tempStr = str1[i];
				string tempAns = tempStr;
				int j2Start = j+1;
				for(int i2=i+1;i2<str1.size();i2++){
					for(int j2=j2Start;j2<str2.size();j2++){
						if(str1[i2]==str2[j2]){
							tempSize++;
							tempAns += str1[i2];
							j2Start = j2+1;
							break;
						}
					}
				}
				if(size<tempSize){
					size = tempSize;
					ans = tempAns;
				}
			}
		}
	}
	cout<<size<<endl;
	if(size!=0){
		cout<<ans;
	}
	
	return 0;
}