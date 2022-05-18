#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10001;

int dfn[MAX];
int low[MAX];

vector<int> adj[MAX];
vector<int> arti;
int v,e;

int dfnCnt = 1;

int getLow(int now,int parent){
	if(dfn[now]!=MAX){
		return MAX;
	}
	//cout<<"now :"<<now<<" parent: "<<parent<<endl;
	dfn[now] = dfnCnt++;
	low[now] = dfn[now];
	bool isArti = false;
	int isExist = 0;
	for(auto next : adj[now]){
		if(next == parent){
			continue;
		}
		if(dfn[next] == MAX){
			isExist++;
			int nextLow = getLow(next,now);
			if(nextLow >= dfn[now]){
				isArti =true;
			}
			low[now] = min(low[now],nextLow);
		}
	}
	//cout<<"V:"<<now<<", dfn:"<<dfn[now]<<", low:"<<low[now]<<endl;
	for(auto next : adj[now]){
		if(next == parent){
			continue;
		}
		if(dfn[next] !=MAX){
			low[now] = min(low[now],low[next]);
		}
	}
	if(parent ==-1 && isExist>1 && isArti){
		arti.push_back(now);
	}
	else if(parent != -1 &&isArti && adj[now].size()>1){
		arti.push_back(now);
	}
	return low[now];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>v>>e;
	for(int i=1;i<=v;i++){
		dfn[i] = MAX;
		low[i] = MAX;
	}
	
	for(int i=0;i<e;i++){
		int s,e;
		cin>>s>>e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	
	for(int i=1;i<=v;i++){
		if(dfn[i] ==MAX){
			getLow(i,-1);
		}
	}
	
	sort(arti.begin(),arti.end());
	cout<<arti.size()<<'\n';
	for(int item : arti){
		cout<<item<<' ';
	}
	return 0;
}