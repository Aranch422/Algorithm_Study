#include <iostream>

using namespace std;

int main(){
	int A,B;
	cin>>A>>B;
	
	int ans =1;
	while(true){
		ans++;
		if(B%2==0) B= B/2;
		else if(B%10 ==1) B = B/10;
		else{
			cout<<-1;
			break;
		}
		if(A>B){
			cout<<-1;
			break;
		}
		
		if(A==B){
			cout<<ans;
			break;
		}
	
	}
	return 0;
}
