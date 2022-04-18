#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> pic1,pic2;

int fail[200000];

void makeFail(vector<int>& diff){
	int cnt = 0;
	for(int i=1;i<n;i++){
		if( diff[i] == diff[cnt]){
			cnt++;
			fail[i] = cnt;
		}
		else{
			while(diff[i]!=diff[cnt] && cnt!=0){
				cnt = fail[cnt-1];
			}
			if(diff[i] == diff[cnt]){
				cnt++;
			}
			fail[i] = cnt;
		}
	}
}

int main(){
	cin>>n;
	vector<int> diff1(n);
	vector<int> diff2(n);
	for(int i=0;i<n;i++){
		fail[i] = 0;
		int temp;
		cin>>temp;
		pic1.push_back(temp);
	}
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		pic2.push_back(temp);
	}
	sort(pic1.begin(),pic1.end());
	sort(pic2.begin(),pic2.end());
	
	for(int i=1;i<n;i++){
		pic1[i] -= pic1[0];
		pic2[i] -= pic2[0];
	}
	pic1[0] = 0;
	pic2[0] = 0;
	
	for(int i=0;i<n-1;i++){
		diff1[i] = pic1[i+1]-pic1[i];
		diff2[i] = pic2[i+1]-pic2[i];
	}
	diff1[n-1] = 360000-pic1[n-1];
	diff2[n-1] = 360000-pic2[n-1];

	// nlogn for now.
	makeFail(diff2);
	int j=0;
	bool isLastLap = false;
	for(int i=0;i<n;i++){
		if(diff1[i] == diff2[j]){
			j++;
		}
		else{
			while(diff1[i]!=diff2[j] && j!=0){
				j = fail[j-1];
			}
			if(diff1[i] == diff2[j]){
				j++;
			}
		}
		if(j==n){
			cout<<"possible";
			return 0;
		}
		if(j>0 && i==n-1 && !isLastLap){
			i=-1;
			isLastLap = true;
		}
	}
	cout<<"impossible";
	
	return 0;
}