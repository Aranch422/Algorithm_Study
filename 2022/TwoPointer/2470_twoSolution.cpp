#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int n;
int pointer = 0;
vector<int> solution;

int biSearch(int left,int right, int target){
	int mid = (left+right)/2;
	if(left == right){
		if(solution[mid] == target){
			return mid;
		}
		else if(solution[mid]<target){
			if(mid+1>=n){
				return mid;
			}
			if(abs(solution[mid]-target)<abs(solution[mid+1]-target)){
				return mid;
			}
			else{
				return mid+1;
			}
		}
		else if(solution[mid]>target){
			if(mid-1<=pointer){
				return mid;
			}
			if(abs(solution[mid]-target)<abs(solution[mid-1]-target)){
				return mid;
			}
			else{
				return mid-1;
			}
		}
	}
	else{
		if(solution[mid]==target){
			return mid;
		}
		else if(solution[mid]<target){
			return biSearch(mid+1,right,target);
		}
		else{
			return biSearch(left,mid,target);
		}
	}
	return -1;
}

int main(){
	cin>>n;
	
	int answer[2];
	int gap=2100000000;
	
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		solution.push_back(temp);
	}
	sort(solution.begin(),solution.end());
	int target;
	while(pointer<n-1){
		target = -solution[pointer];
		int loc = biSearch(pointer+1,n-1,target);
		int tempGap = abs(solution[pointer]+solution[loc]);
		if(tempGap<gap){
			gap = tempGap;
			answer[0] = solution[pointer];
			answer[1] = solution[loc];
		}
		//cout<<pointer<<" "<<loc<<endl;
		//cout<<solution[pointer]<<" "<<solution[loc]<<" "<<gap<<endl;
		pointer++;
	}
	//cout<<gap;
	answer[0]<answer[1]? cout<<answer[0]<<" "<<answer[1]:cout<<answer[1]<<" "<<answer[0];
	return 0;
}