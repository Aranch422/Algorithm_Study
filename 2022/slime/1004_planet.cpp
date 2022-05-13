#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct point{
	int x,y,r;
	point(int x,int y, int r):x(x), y(y), r(r){}
};


bool isIn(point P1, point P2){
	return sqrt( pow(P2.x-P1.x ,2) + pow(P2.y-P1.y,2))<= P2.r;
}

bool cmp(point a, point b){
	return a.r<b.r;
}


int main(){
	int t;
	cin>>t;
	
	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		point p1 = point(a,b,0);
		point p2 = point(c,d,0);
		
		int n;
		cin>>n;
		vector<point> planets;
		int cntA =0;
		int cntB =0;
		while(n--){
			int x,y,r;
			cin>>x>>y>>r;
			point C = point (x,y,r);
			planets.push_back(C);
		}
		sort(planets.begin(),planets.end(),cmp);
		for(auto planet : planets){
			if(isIn(p1,planet) && isIn(p2,planet)){
				break;
			}
			else if(isIn(p1,planet)){
				cntA++;
			}
			else if(isIn(p2,planet)){
				cntB++;
			}
		}
		cout<<cntA+cntB<<"\n";
	}

	return 0;
}