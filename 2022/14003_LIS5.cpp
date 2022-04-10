#include <iostream>
#include <vector>

using namespace std;

int n;

int num[1000000];
int Len[1000000];

vector<int> Lis;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
		if(Lis.empty() || Lis[Lis.size()-1]<num[i]){
			Lis.push_back(num[i]);
			Len[i] = Lis.size();
		}
		else{
			int left = 0;
			int right = Lis.size()-1;
			while(left<right){
				int mid = (left+right)/2;
				if(Lis[mid]<num[i]) left =mid+1;
				else if(Lis[mid]==num[i]){
					left =mid;
					break;
				}
				else{
					right = mid;
				}
			}
			Lis[left] = num[i];
			Len[i] = left+1;
		}
	}
	int Size = Lis.size();
	int number = Lis[Lis.size()-1];
	vector<string> answer;
	answer.push_back( to_string( number ) );
	int loc;
	for(int i=n-1;i>=0;i--){
		if(Len[i] == Size && num[i] == number){
			loc = i;
			Size--;
			break;
		}
	}
	for(int i=loc;i>=0;i--){
		if(Len[i]==Size && num[i]<number){
			number = num[i];
			Size--;
			answer.push_back( to_string( number ) + " " );
		}
	}
	
	cout<<Lis.size()<<"\n";
	for(int i=answer.size()-1;i>=0;i--){
		cout<<answer[i];
	}
	
	return 0;
}