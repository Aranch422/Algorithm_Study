#include <iostream>

using namespace std;

long long MOD = 1000000007;

long long len;

class Mat{
public:
	long long mat[2][2];
	Mat(){
		mat[0][0] = 1;
		mat[0][1] = 0;
		mat[1][0] = 0;
		mat[1][1] = 1;
	}
	Mat(long long a, long long b, long long c, long long d){
		mat[0][0] = a;
		mat[0][1] = b;
		mat[1][0] = c;
		mat[1][1] = d;
	}
	
	static Mat* mul(Mat* A, Mat* B){
		long long lu = A->mat[0][0]*B->mat[0][0] + A->mat[0][1]*B->mat[1][0];
		long long ru = A->mat[0][0]*B->mat[0][1] + A->mat[0][1]*B->mat[1][1];
		long long ld = A->mat[1][0]*B->mat[0][0] + A->mat[1][1]*B->mat[1][0];
		long long rd = A->mat[1][0]*B->mat[0][1] + A->mat[1][1]*B->mat[1][1];
		lu = lu%MOD;
		ru = ru%MOD;
		ld = ld%MOD;
		rd = rd%MOD;
		return new Mat(lu,ru,ld,rd);
	}
};


Mat* base = new Mat(1,1,1,0);

Mat* div_conq(long long n){
	if(n == 1) return base;
	
	bool isOdd = false;
	if(n%2 ==1) {
		n=n-1;
		isOdd =true;
	}	
	Mat* half = div_conq(n/2);
	Mat* complete = Mat::mul(half,half);
	if(isOdd){
		Mat* ret = Mat::mul(complete,base);
		return ret;
	}
	else{
		return complete;
	}
}

int main(){
	cin>>len;
	if(len == 1){
		cout<<1;
	}
	else if(len==0){
		cout<<0;
	} else{
		Mat* d = div_conq(len-1);
		cout<<d->mat[0][0];
	}
	return 0;
}
