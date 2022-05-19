#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100000;

int n,d;
int Start[MAX];
int End[MAX];

pair<int,int> roads[MAX];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(a>b){
			swap(a,b);
		}
		roads[i] = {a,b};
	}
	cin>>d;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(roads[i].second-roads[i].first<=d){
			Start[cnt] = roads[i].first-(d-(roads[i].second-roads[i].first));
			End[cnt] = roads[i].first;
			if(Start[cnt]<-100000000){
				Start[cnt] = -100000000;
			}
			cnt++;
		}
	}
	sort(Start,Start+cnt);
	sort(End,End+cnt);
	int sIdx=0;
	int eIdx=0;
	
	int temp =0;
	int ans =0;
	while(sIdx < cnt){
		
		if(Start[sIdx]<=End[eIdx]){
			temp++;
			sIdx++;
			ans = max(temp,ans);
		}
		else if(Start[sIdx]>End[eIdx]){
			temp--;
			eIdx++;
		}
	}
	cout<<ans;

	return 0;
}
