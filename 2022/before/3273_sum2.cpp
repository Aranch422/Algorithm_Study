#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x;
int first;

vector<int> myVec;
vector<int> abbrVec;
vector<int> countVec;
int answer = 0;

int binarySearch(int left,int right, int target){
	//cout<<left<<" "<<right<<endl;
	int mid = (left+right)/2;
	if(left>right){
		return -1;
	}
	
	if(left == right) {
		if(abbrVec[mid] == target){
			return mid;
		}
		else {
			return -1;
		}
	};
	
	if(abbrVec[mid] == target){
		return mid;
	}
	else{
		if(target<abbrVec[mid]) return binarySearch(left,mid,target);
		else if(target>abbrVec[mid]) {
			return binarySearch(mid+1,right,target);
		}
	}
	return 0;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		myVec.push_back(temp);
	}
	cin>>x;
	sort(myVec.begin(),myVec.end());
	int now = myVec[0];
	int count = 1;
	for(int i=1;i<n;i++){
		if(now == myVec[i]) count++;
		else{
			abbrVec.push_back(now);
			countVec.push_back(count);
			count = 1;
			now = myVec[i];
		}
	}
	abbrVec.push_back(now);
	countVec.push_back(count);
	int target = x-abbrVec[first];
	int len = abbrVec.size();
	first = 0;
	while(true){
		if(target<0) break;
		int loc = binarySearch(first+1,len-1,target);
		if(loc>=0){
			int temp = countVec[first]*countVec[loc];
			answer += temp;
		}
		first++;
		if(first>=len-1) break;
		target = x-abbrVec[first];
	}
	cout<<answer;
	
	return 0;
}