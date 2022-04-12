#include <iostream>

using namespace std;

long long n;

//to get Inverse Elem
long long Uclid_ext(long long p, long long a){
	long long s1,s2,t1,t2,r1,r2,q;
	long long s,t,r;
	r1=p; r2=a;
	s1=1; s2=0;
	t1=0; t2=1;

	while(r2!=0){
		q = r1/r2;	
		r = r1 - r2*q;
		
		s = s1 - s2*q;
		t = t1 - t2*q;
		
		s1 = s2; s2 = s;
		t1 = t2; t2 = t;
		r1 = r2; r2 = r;
	}
	if(t1<0) t1 = t1+p;
	return t1;
}

long long fac97[97],fac1031[1031];
long long invFac97[97],invFac1031[1031];

void init(){
	fac97[0]=1;
	for(long long i=1;i<97;i++){
		fac97[i] = (fac97[i-1]*i)%97;
		//cout<<i<<" "<<fac97[i]<<endl;
	}
	fac1031[0]=1;
	for(long long i=1;i<1031;i++){
		fac1031[i] = (fac1031[i-1]*i)%1031;
	}
	
	invFac97[96] = Uclid_ext(97,fac97[96]);
	for(long long i=95;i>=0;i--){
		invFac97[i] = (invFac97[i+1]*(i+1))%97;
		//cout<<i<<" "<<invFac97[i]<<endl;
	}
	
	invFac1031[1030] = Uclid_ext(1031,fac1031[1030]);
	for(long long i=1029;i>=0;i--){
		invFac1031[i] = (invFac1031[i+1]*(i+1))%1031;
	}
}

long long Lucas(long long m,long long n, long long p){
	//m>0 n>0
	long long* fac;
	long long* invFac;
	if( p == 97){
		fac = fac97;
		invFac = invFac97;
	}
	else{
		fac = fac1031;
		invFac = invFac1031;
	}
	bool isOneofThemZero = false;
	if(m==0 && n ==0) isOneofThemZero = true;
	long long temp = 1;
	while(isOneofThemZero == false){
		long long mr = m%p;
		long long nr = n%p;
		m=m/p; n=n/p;
		if(mr<nr) return 0;
		long long combination = (fac[mr]*invFac[mr-nr]*invFac[nr])%p;
		temp = (temp * combination)%p;
		if(m==0 && n ==0) isOneofThemZero = true;
	}
	return temp;
}

int main(){
	cin>>n;
	init();
	long long a1,a2,n1,n2,s1,s2;
	n1=1031ll;n2=97ll;
	
	for(long long i=0;i<97;i++){
		if((61*i)%97 == 1){
			s1=i;
			break;
		}
	}
	
	for(long long i=0;i<1031;i++){
		if((97*i)%1031 == 1){
			s2=i;
			break;
		}
	}
	while(n-->0){
		long long ball, day;
		cin>>ball>>day;
		if(ball == 0){
			if(day==1){
				cout<<1<<endl;
				continue;
			}
			else{
				cout<<0<<endl;
				continue;
			}
		}
		
		if(day==1){
			//ball>2
			cout<<0<<endl;
			continue;
		}
		a1 = Lucas(ball-1,day-2,97);
		a2 = Lucas(ball-1,day-2,1031);
		//cout<<a1<<" "<<a2<<endl;
		//cout<<s1<<" "<<s2<<endl;
		cout<<(a1*n1*s1+a2*n2*s2)%100007<<endl;
		//ball-1 C day-2
		
	}
	return 0;
}