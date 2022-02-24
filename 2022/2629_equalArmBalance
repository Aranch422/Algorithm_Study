#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int weight[40001];
int numOfChu;
int numOfBall;

void init(){
	cin>>numOfChu;
	memset(weight,0,sizeof(weight));
	
	for(int i=0;i<numOfChu;i++){
		int chuWeight;
		cin>>chuWeight;
		vector<int> update;
		update.push_back(chuWeight);
		for(int j=0;j<=40000;j++){
			if(weight[j]==1){
				if(j+chuWeight<=40000){
					update.push_back(j+chuWeight);
				}
				int temp = j-chuWeight;
				if (temp<0) temp= -temp;
				update.push_back(temp);
			}
		}
		
		for(int i=0;i<update.size();i++){
			weight[update[i]]=1;
		}

	}
	
}



int main(){
	init();
	cin>>numOfBall;
	for(int i=0;i<numOfBall;i++){
		int target;
		cin>>target;
		if(weight[target]==1) cout<<"Y";
		else cout<<"N";
		if(i == numOfBall-1){
			break;
		}
		cout<<" ";
	}
	
	return 0;
}
