#include <iostream>

using namespace std;

int n;

int PRIME1 = 97;
int PRIME2 = 1031;

int  main(){
	cin>>n;
	while(n>0){
		n--;
		int ball,day;
		int a1,a2,s1,s2;
		cin>>ball>>day;
		
		if (ball == day-1){
			cout<< 1<<endl;
			continue;
		}
		else if(ball<day-1){
			cout<<0<<endl;
			continue;
		}
		
		//ball>=day
		if( day == 1){
			cout<<0<<endl;
			continue;
		}
		
		if(day==2) {
			cout<<1<<endl;
			continue;
		}
		
		//97 check
		if(day-2>=PRIME1) a1 =0;
		else{
			int r1 = (ball-1)%PRIME1;
			int r2 = (ball-day+2)%PRIME1;
				
			if(r1 < r2){
				a1 = 0;
			}
			else{
				a1=1;
				for( int i=r2;i<=r1;i++){
					a1 = a1*i;
					a1 = a1%PRIME1;
				}
			}
		}
		
		for(int i=0;i<PRIME1;i++){
			if((61*i)%PRIME1 == 1){
				s1=i;
				break;
			}
		}
		
		//1031 check
		if(day-2>=PRIME2) a2 =0;
		else{
			int r1 = (ball-1)%PRIME2;
			int r2 = (ball-day+2)%PRIME2;
				
			if(r1 < r2){
				a2 = 0;
			}
			else{
				a2=1;
				for( int i=r2;i<=r1;i++){
					a2 = a2*i;
					a2 = a2%PRIME2;
				}
			}
		}
		
		cout<<(a1*PRIME2*s1+a2*PRIME1*s2)%100007<<endl;
	}
	return 0;
}