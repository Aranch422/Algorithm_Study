#include <iostream>

using namespace std;

double x1,x2,x3,x4;
double my1,y2,y3,y4;

double xlist[5];
double ylist[5];

void init(){
    cin>>x1>>my1>>x2>>y2>>x3>>y3>>x4>>y4;
    xlist[1]=x1; xlist[2]=x2; xlist[3]=x3; xlist[4]=x4;
    ylist[1]=my1; ylist[2]=y2; ylist[3]=y3; ylist[4]=y4;

}

double cross(int a,int b,int c){
    double xx1=xlist[b]-xlist[a];
    double yy1=ylist[b]-ylist[a];
    double xx2=xlist[c]-xlist[a];
    double yy2=ylist[c]-ylist[a];
    if(xx1*yy2-xx2*yy1>0) return 1;
	else if(xx1*yy2-xx2*yy1==0) return 0;
    else return -1;
}

int solve(){
    double ccw1,ccw2;
    ccw1=cross(1,2,3);
    ccw2=cross(1,2,4);
    //cout<<ccw1<<" "<<ccw2<<endl;
	if(ccw1==0 && ccw2==0){
		double smallX,bigX;
		smallX = (xlist[1]<xlist[2])? xlist[1]:xlist[2];
		bigX = (xlist[1]>xlist[2])? xlist[1]:xlist[2];
		
		if(smallX>xlist[3] && smallX>xlist[4]){
			cout<<0;
			return 0;
		}
		else if(bigX<xlist[3] && bigX<xlist[4]){
			cout<<0;
			return 0;
		}
		else{
			double smallY,bigY;
			smallY = (ylist[1]<ylist[2])? ylist[1]:ylist[2];
			bigY = (ylist[1]>ylist[2])? ylist[1]:ylist[2];

			if(smallY>ylist[3] && smallY>ylist[4]){
				cout<<0;
				return 0;
			}
			else if(bigY<ylist[3] && bigY<ylist[4]){
				cout<<0;
				return 0;
			}
			else{
				cout<<1;
				if(x1==x2 && x3==x4){
					if(smallY == y3 && y4<=y3){
						return 1;
					}
					else if(smallY == y4 && y3<=y4){
						return 1;
					}
					else if(bigY == y3 && y3<=y4){
						return 1;
					}
					else if(bigY == y4 && y4<=y3){
						return 1;
					}
					else{
						return -1;
					}
				}
				else if(smallX == x3 && x4<=x3){
					return 1;
				}
				else if(smallX == x4 && x3<=x4){
					return 1;
				}
				else if(bigX == x3 && x3<=x4){
					return 1;
				}
				else if(bigX == x4 && x4<=x3){
					return 1;
				}
				else{
					return -1;
				}
			}
		}
	}
    else if(ccw1*ccw2<=0){
        double ccw3=cross(3,4,1);
        double ccw4=cross(3,4,2);
        //cout<<ccw1<<" "<<ccw2<<endl;
        if(ccw3*ccw4<=0){
            cout<<1;
            return 1;
        }
    }
    cout<<0;
	return 0;
}

int main(){
	cout<<fixed;
	cout.precision(10);
    init();
    int ret =solve();
	bool isCrossed=false;
	if(ret == 1) isCrossed = true;
	cout<<endl;
	if(isCrossed){
		double a1,a2,b1,b2;
		if(x1 == x2 && x3!=x4){
			a2 = (y4-y3)/(x4-x3);
			b2 = y3-a2*x3;
			cout<<x1<<" "<<a2*x1+b2;
		}
		else if(x1!=x2 && x3==x4){
			a1 = (y2-my1)/(x2-x1);
			b1 = my1-a1*x1;
			cout<<x3<<" "<<a1*x3+b1;
		}
		else if(x1==x2 && x3 ==x4){
			if(my1==y3 || my1 == y4){
				cout<<x1<<" "<<my1;
			}
			else{
				cout<<x2<<" "<<y2;
			}
		}
		else{
			a1 = (y2-my1)/(x2-x1);
			a2 = (y4-y3)/(x4-x3);
			b1 = my1-a1*x1;
			b2 = y3-a2*x3;
			if(a1==a2){
				if(x1==x3 || x1 == x4){
					cout<<x1<<" "<<my1;
				}
				else{
					cout<<x2<<" "<<y2;
				}

			}
			else{
				double ansX = (b2-b1)/(a1-a2);
				double ansY = a1*ansX+b1;
				cout<<ansX<<" "<<ansY;			
			}
		}
	}
    return 0;
}