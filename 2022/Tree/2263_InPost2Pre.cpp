#include <iostream>

using namespace std;

int n;

int In[100001];
int Post[100001];
bool isVisited[100001];
int count = 0;

void Pre(int InL,int InR,int PostL, int PostR, int num){
	if(InL>InR) return;
	if(isVisited[num]) return;
	else isVisited[num]=true;
	if(InL == InR){
		count++;
		if(count==n){
			cout<<num;
		}
		else cout<<num<<" ";
		return;
	}
	int loc;
	for(int i = InL;i<=InR;i++){
		if(In[i]==num){
			loc = i;
			break;
		}
	}
	count++;
	if(count==n){
		cout<<num;
	}
	else cout<<num<<" ";
	Pre(InL,loc-1,PostL,PostL+loc-1-InL,Post[PostL+loc-1-InL]);
	Pre(loc+1,InR,PostL+loc-InL,PostR-1,Post[PostR-1]);
}
int main(){
	cin>>n;
	for(int i=0;i<=n;i++){
		isVisited[i] = false;
	}
	for(int i=0;i<n;i++){
		cin>>In[i];
	}
	for(int i=0;i<n;i++){
		cin>>Post[i];
	}
	Pre(0,n-1,0,n-1,Post[n-1]);
	return 0;
}