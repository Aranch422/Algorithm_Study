#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>

using namespace std;

int num[500000];
int freq[8001];

int len;

int sum = 0;
int mini =5000;
int maxi = -5000;

bool compare(int a, int b){
	return a<b;
}

int main(){
	memset(freq,0,sizeof(freq));
	cin>>len;
	for(int i=0; i<len; i++){
		cin>>num[i];
		freq[num[i]+4000]++;
		sum += num[i];
		
		if(mini>num[i]) mini = num[i];
		if(maxi<num[i]) maxi = num[i];
	}
	int mean = (int)(round(sum/float(len)));
	cout<<mean<<endl;
	
	sort(num,num+len);
	len = len-1;
	cout<<num[len/2]<<endl;
	
	int most=-1;
	int mostIdx=0;
	
	vector<int> freqs;
	for(int i=0;i<8001;i++){
		if(most == freq[i]){
			mostIdx = i-4000;
			freqs.push_back(mostIdx);
		}
		else if(most<freq[i]) {
			freqs.clear();
			vector<int>().swap(freqs);
			most = freq[i];
			mostIdx = i-4000;
			freqs.push_back(mostIdx);
		}
	}
	sort(freqs.begin(),freqs.end());
	
	if(freqs.size()>1){
		cout<<freqs[1]<<endl;
	}else{
		cout<<freqs[0]<<endl;
	}
	
	cout<<maxi-mini<<endl;
	
	
	return 0;
}
