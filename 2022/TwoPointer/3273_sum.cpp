#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x;
int first;
vector<int> myVec;
int answer = 0;

void binarySearch(int left,int right, int target){
	int mid = (left+right)/2;
	
	if(left == right) {
		if(myVec[mid] == target){
			answer++;
		}
		return;
	};
	
	if(myVec[mid] == target){
		answer++;
		int windowLeft = mid-1;
		//left
		if(windowLeft>first){
			while(myVec[windowLeft]==target){
				answer++;
				windowLeft--;
				if(windowLeft<=first) break;
			}	
		}
		int windowRight = mid+1;
		if(windowRight<n){
			while(myVec[windowRight]==target){
				answer++;
				windowRight++;
				if(windowRight>=n) break;
			}			
		}

		return;
	}
	else{
		if(target<myVec[mid]) binarySearch(left,mid,target);
		else if(target>myVec[mid]) {
			binarySearch(mid+1,right,target);
		}
	}
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
	first = 0;
	int before;
	int after;
	int gap;
	int target = x-myVec[first];
	while(true){
		if(target<0) break;
		before= answer;
		binarySearch(first+1,n-1,target);
		after = answer;
		gap = after - before;
		first++;
		if(first>=n-1) break;

		while(target == x-myVec[first]){
			answer = answer + gap;
			first++;
			if(first>=n-1) break;
		}
		if(first>=n-1) break;
		else{
			target = x - myVec[first];
		}

	}
	cout<<answer;
	return 0;
}