#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;

vector<int> alphabet[26];

int binSearch(int idx, int target, int left, int right){
	int mid = (left + right)/2;
	if(left == right){
		return mid;
	}
	if(alphabet[idx][mid]== target){
		return mid;
	}
	else if(alphabet[idx][mid]<target){
		return binSearch(idx,target,mid+1,right);
	}
	else{
		return binSearch(idx,target,left,mid);
	}
}

int findA(string a, int left, int right){
	int idx = a[0]-97;
	if(alphabet[idx].size()==0){
		return 0;
	}
	int numR = binSearch(idx, right, 0, alphabet[idx].size()-1);
	if(alphabet[idx][numR]>right){
		numR--;
	}
	
	int numL = binSearch(idx, left, 0, alphabet[idx].size()-1);
	if(alphabet[idx][numL]<left){
		numL++;
	}
	//cout<<numR<<" "<<numL<<endl;
	return numR-numL+1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin>>str;
	for(int i=0;i<str.size();i++){
		alphabet[str[i]-97].push_back(i);
	}
	for(int i=0;i<26;i++){
		sort(alphabet[i].begin(),alphabet[i].end());
	}
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		int a,b;
		cin>>s>>a>>b;
		cout<<findA(s,a,b)<<"\n";
	}
	return 0;
}