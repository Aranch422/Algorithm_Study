#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leftV[15],rightV[15];

int n,c;
vector<int> clusterL,clusterR;
int biSearch(int left, int right, int target){
	int mid = (left+right)/2;
	if(left == right){
		if(clusterR[mid]==target) return mid +1;
		else if(clusterR[mid]<target) return mid +1;
		else return mid;
	}
	if(clusterR[mid]==target) {
		return biSearch(mid+1,right,target);
	}
	else if(clusterR[mid]<target) {
		return biSearch(mid+1,right,target);
	}
	else return biSearch(left,mid,target);
	
}


int main(){
	cin>>n>>c;
	int num[30];
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	if(n == 1){
		if (num[0]<=c) cout<<2;
		else cout<<1;
		return 0;
	}

	int mid = n/2;
	
	leftV[0].push_back(0);
	if(num[0]<=c){
		leftV[0].push_back(num[0]);	
	}
	
	for(int i=1;i<mid;i++){
		vector<int> before = leftV[i-1];
		for(int j=0;j<before.size();j++){
			leftV[i].push_back(before[j]);
			if(before[j]+num[i]<=c){
				leftV[i].push_back(before[j]+num[i]);	
			}
		}
	}
	
	rightV[0].push_back(0);
	if(num[mid]<=c){
		rightV[0].push_back(num[mid]);		
	}

	
	for(int i=mid+1;i<n;i++){
		vector<int> before = rightV[i-mid-1];
		for(int j=0;j<before.size();j++){
			rightV[i-mid].push_back(before[j]);
			if(before[j]+num[i]<=c){
				rightV[i-mid].push_back(before[j]+num[i]);
			}
		}
	}
	clusterL = leftV[mid-1];
	clusterR = rightV[n-mid-1];
	sort(clusterR.begin(),clusterR.end());
	int ans = 0;
	for(int i=0;i<clusterL.size();i++){
		int target = c- clusterL[i];
		int temp = biSearch(0,clusterR.size()-1,target);
		ans +=temp;
	}
	cout<<ans;
	return 0;
}