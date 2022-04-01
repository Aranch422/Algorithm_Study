#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,s;
vector<int> sum;
int start,end;

int biSearch(int left,int right, int target){
	int mid = (left+right)/2;
	if(left == right){
		if(sum[mid]==target){
			return mid;
		}
		else if(sum[mid]<target){
			if(mid+1>=n){
				return -1;
			}
			else{
				return mid+1;
			}
		}
		else{
			return mid;
		}
	}
	if(sum[mid]==target){
		return mid;
	}
	else if(sum[mid]<target){
		return biSearch(mid+1,right,target);
	}
	else{
		return biSearch(left,mid,target);
	}
	return -1;
}

int main(){
	cin>>n>>s;
	int tempSum=0;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		tempSum+=temp;
		sum.push_back(tempSum);
	}
	int minimum=100001;
	for(int i=0;i<n;i++){
		if(sum[i]>=s){
			minimum = i+1;
			break;
		}
	}
	for(start=1;start<n;start++){
		int target= sum[start-1]+s;
		int loc = biSearch(start,n-1,target);
		//cout<<loc<<endl;
		if (loc== -1) continue;
		else{
			int tempMin = loc-start+1;
			if(tempMin<minimum){
				minimum = tempMin;
			}
		}
	}
	if(minimum==100001){
		minimum = 0;
	}
	cout<<minimum;
	return 0;
}