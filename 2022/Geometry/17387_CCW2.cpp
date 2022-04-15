#include <iostream>

using namespace std;

long long x1,x2,x3,x4;
long long my1,y2,y3,y4;
double a1,a2;

long long xlist[5];
long long ylist[5];

void init(){
    cin>>x1>>my1>>x2>>y2>>x3>>y3>>x4>>y4;
    xlist[1]=x1; xlist[2]=x2; xlist[3]=x3; xlist[4]=x4;
    ylist[1]=my1; ylist[2]=y2; ylist[3]=y3; ylist[4]=y4;

}

long long cross(long long a,long long b,long long c){
    long long xx1=xlist[b]-xlist[a];
    long long yy1=ylist[b]-ylist[a];
    long long xx2=xlist[c]-xlist[a];
    long long yy2=ylist[c]-ylist[a];
    if(xx1*yy2-xx2*yy1>0) return 1;
	else if(xx1*yy2-xx2*yy1==0) return 0;
    else return -1;
}

void solve(){
    long long ccw1,ccw2;
    ccw1=cross(1,2,3);
    ccw2=cross(1,2,4);
    //cout<<ccw1<<" "<<ccw2<<endl;
	if(ccw1==0 && ccw2==0){
		long long smallX,bigX;
		smallX = (xlist[1]<xlist[2])? xlist[1]:xlist[2];
		bigX = (xlist[1]>xlist[2])? xlist[1]:xlist[2];
		
		if(smallX>xlist[3] && smallX>xlist[4]){
			cout<<0;
			return;
		}
		else if(bigX<xlist[3] && bigX<xlist[4]){
			cout<<0;
			return;
		}
		else{
			long long smallY,bigY;
			smallY = (ylist[1]<ylist[2])? ylist[1]:ylist[2];
			bigY = (ylist[1]>ylist[2])? ylist[1]:ylist[2];

			if(smallY>ylist[3] && smallY>ylist[4]){
				cout<<0;
				return;
			}
			else if(bigY<ylist[3] && bigY<ylist[4]){
				cout<<0;
				return;
			}
			else{
				cout<<1;
				return ;
			}
		}
	}
    else if(ccw1*ccw2<=0){
        long long ccw3=cross(3,4,1);
        long long ccw4=cross(3,4,2);
        //cout<<ccw1<<" "<<ccw2<<endl;
        if(ccw3*ccw4<=0){
            cout<<1;
            return;
        }
    }
    cout<<0;
}

int main(){
    init();
    solve();
    return 0;
}