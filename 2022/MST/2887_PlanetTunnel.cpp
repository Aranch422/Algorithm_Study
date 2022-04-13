#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

long long n;

struct planet{
	long long num;
	long long x,y,z;
	planet(long long name, long long xx, long long yy, long long zz) : num(name), x(xx), y(yy), z(zz) {}
	long long xIdx,xLeft,xRight;
	long long yIdx,yLeft,yRight;
	long long zIdx,zLeft,zRight;
};

vector<planet*> Xorder,Yorder,Zorder;
vector<planet*> Planets;

bool isVisit[100000];
long long visitCnt=0;

struct edge{
	long long start;
	long long end;
	long long cost;
	edge(long long s,long long e,long long c) : start(s), end(e), cost(c) {}

	bool operator<(edge e) const{
		return this->cost>e.cost;
	}
};

priority_queue<edge> Edges;

bool cmpX(planet* a, planet* b){
	return a->x<b->x;
}

bool cmpY(planet* a, planet* b){
	return a->y<b->y;
}

bool cmpZ(planet* a, planet* b){
	return a->z<b->z;
}

const long long INF = 2123456789;

edge getSmallEdge(planet* P){
	long long shortX,shortY,shortZ;
	long long xL,xR,yL,yR,zL,zR;
	
	
	if(P->xLeft<0 && P->xRight>=n){
		shortX = INF;
	}
	else if(P->xLeft<0) {
		xL = INF;
		xR = abs(Xorder[P->xIdx]->x-Xorder[P->xRight]->x);
		shortX=xR;
	}
	else if(P->xRight>=n){
		xL = abs(Xorder[P->xIdx]->x-Xorder[P->xLeft]->x);
		xR = INF;
		shortX = xL;
	}
	else{
		xL = abs(Xorder[P->xIdx]->x-Xorder[P->xLeft]->x);
		xR = abs(Xorder[P->xIdx]->x-Xorder[P->xRight]->x);
		shortX= (xL < xR)? xL:xR;
	}
	//cout<<shortX<<" ";
	
	if(P->yLeft<0 && P->yRight>=n){
		shortY = INF;
	}
	else if(P->yLeft<0) {
		yL = INF;
		yR = abs(Yorder[P->yIdx]->y-Yorder[P->yRight]->y);
		shortY=yR;
	}
	else if(P->yRight>=n){
		yL = abs(Yorder[P->yIdx]->y-Yorder[P->yLeft]->y);
		yR = INF;
		shortY = yL;
	}
	else{
		yL = abs(Yorder[P->yIdx]->y-Yorder[P->yLeft]->y);
		yR = abs(Yorder[P->yIdx]->y-Yorder[P->yRight]->y);
		shortY= (yL < yR)? yL:yR;
	}
	//cout<<shortY<<" ";
	
	if(P->zLeft<0 && P->zRight>=n){
		shortZ = INF;
	}
	else if(P->zLeft<0) {
		zL = INF;
		zR = abs(Zorder[P->zIdx]->z-Zorder[P->zRight]->z);
		shortZ=zR;
	}
	else if(P->zRight>=n){
		zL = abs(Zorder[P->zIdx]->z-Zorder[P->zLeft]->z);
		zR = INF;
		shortZ = zL;
	}
	else{
		zL = abs(Zorder[P->zIdx]->z-Zorder[P->zLeft]->z);
		zR = abs(Zorder[P->zIdx]->z-Zorder[P->zRight]->z);
		shortZ= (zL < zR)? zL:zR;
	}
	//cout<<shortZ<<endl;
	
	if(shortX<shortY){
		if(shortX<shortZ){
			if(shortX == xL){
				P->xLeft--;
				return edge(P->num,Xorder[P->xLeft+1]->num,shortX);
			}
			else{
				P->xRight++;
				return edge(P->num,Xorder[P->xRight-1]->num,shortX);;
			}
		}
		else{
			if(shortZ == zL){
				P->zLeft--;
				return edge(P->num,Zorder[P->zLeft+1]->num,shortZ);
			}
			else{
				P->zRight++;
				return edge(P->num,Zorder[P->zRight-1]->num,shortZ);
			}
		}
	}
	else{
		if(shortY<shortZ){
			if(shortY == yL){
				P->yLeft--;
				return edge(P->num,Yorder[P->yLeft+1]->num,shortY);
			}
			else{
				P->yRight++;
				return edge(P->num,Yorder[P->yRight-1]->num,shortY);
			}
		}
		else{
			if(shortZ == zL){
				P->zLeft--;
				return edge(P->num,Zorder[P->zLeft+1]->num,shortZ);
			}
			else{
				P->zRight++;
				return edge(P->num,Zorder[P->zRight-1]->num,shortZ);
			}
		}
	}
}

int main(){
	cin>>n;
	for(long long i=0;i<n;i++){
		long long x,y,z;
		cin>>x>>y>>z;
		planet* P = new planet(i,x,y,z);
		Planets.push_back(P);
		Xorder.push_back(P);
		Yorder.push_back(P);
		Zorder.push_back(P);
		isVisit[i] = false;
	}
	sort(Xorder.begin(),Xorder.end(),cmpX);
	sort(Yorder.begin(),Yorder.end(),cmpY);
	sort(Zorder.begin(),Zorder.end(),cmpZ);

	for(long long i=0;i<n;i++){
		Xorder[i]->xIdx = i;
		Xorder[i]->xLeft = i-1;
		Xorder[i]->xRight = i+1;
		
		Yorder[i]->yIdx = i;
		Yorder[i]->yLeft = i-1;
		Yorder[i]->yRight =  i+1;
		
		Zorder[i]->zIdx = i;
		Zorder[i]->zLeft = i-1;
		Zorder[i]->zRight = i+1;
	}
	
	isVisit[0]=true;
	visitCnt++;
	long long totalCost=0;
	
	edge E = getSmallEdge(Planets[0]);
	
	Edges.push(E);
	while(!Edges.empty()){
		E = Edges.top();
		Edges.pop();
		long long start = E.start;
		long long end = E.end;
		long long cost = E.cost;
		if(isVisit[end]){
			Edges.push(getSmallEdge(Planets[start]));
		}
		else{
			isVisit[end]=true;
			visitCnt++;
			totalCost+=cost;
			Edges.push(getSmallEdge(Planets[start]));
			Edges.push(getSmallEdge(Planets[end]));
		}
		
		if(visitCnt>=n) break;
	}
	cout<<totalCost;
	return 0;
}