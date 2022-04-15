#include <iostream>

using namespace std;

int x1,x2,x3,x4;
int my1,y2,y3,y4;

struct line{
	int x1,x2,my1,y2;
	line(){}
	line(int a,int b, int c, int d) : x1(a), my1(b), x2(c), y2(d) {}
};

line Lines[3000];

pair<int,int> cross(line a, line b){
    int xx1=a.x2-a.x1;
    int yy1=a.y2-a.my1;
    int xx2=b.x1-a.x1;
    int yy2=b.my1-a.my1;
	int ret1;
    if(xx1*yy2-xx2*yy1>0) ret1= 1;
	else if(xx1*yy2-xx2*yy1==0) ret1= 0;
    else ret1= -1;
	
	xx2 = b.x2-a.x1;
	yy2 = b.y2-a.my1;
	int ret2;
	if(xx1*yy2-xx2*yy1>0) ret2= 1;
	else if(xx1*yy2-xx2*yy1==0) ret2= 0;
    else ret2= -1;
	return {ret1, ret2};
}

bool isCrossed(line a, line b){
    int ccw1,ccw2;
	pair<int,int> ccw = cross(a,b);
    ccw1=ccw.first;
    ccw2=ccw.second;
    //cout<<ccw1<<" "<<ccw2<<endl;
	if(ccw1==0 && ccw2==0){
		int smallX,bigX;
		smallX = (a.x1<a.x2)? a.x1:a.x2;
		bigX = (a.x1>a.x2)? a.x1:a.x2;
		
		if(smallX>b.x1 && smallX>b.x2){
			return false;
		}
		else if(bigX<b.x1 && bigX<b.x2){
			return false;
		}
		else{
			int smallY,bigY;
			smallY = (a.my1<a.y2)? a.my1:a.y2;
			bigY = (a.my1>a.y2)? a.my1:a.y2;

			if(smallY>b.my1 && smallY>b.y2){
				return false;
			}
			else if(bigY<b.my1 && bigY<b.y2){
				return false;
			}
			else{
				return true;
			}
		}
	}
    else if(ccw1*ccw2<=0){
		ccw = cross(b,a);
        int ccw3=ccw.first;
        int ccw4=ccw.second;
        //cout<<ccw1<<" "<<ccw2<<endl;
        if(ccw3*ccw4<=0){
            return true;
        }
    }
    return false;
}

int n;

struct node{
	node* parent;
	int level;
};

node* Nodes[3000];

node* find(node* me){
	node* ori = me;
	while(me->parent!=NULL){
		me = me->parent;
	}
	node* root = me;
	me = ori;
	while(me->parent!=NULL){
		ori = me;
		me = me->parent;
		ori->parent = root;
	}
	return root;
}

void Union(node* a,node* b){
	a = find(a);
	b = find(b);
	if(a != b){
		a->parent = b;
		b->level += a->level;
	}
}

bool isInSameGroup(node* a, node* b){
	a = find(a);
	b = find(b);
	return a==b;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		Lines[i] = line(a,b,c,d);
		Nodes[i] = new node();
		Nodes[i]->parent=NULL;
		Nodes[i]->level = 1;
	}
    for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(isCrossed(Lines[i],Lines[j])){
				if(!isInSameGroup(Nodes[i],Nodes[j])){
					Union(Nodes[i],Nodes[j]);
				}
			}
		}
	}
	
	int groupCnt = 0;
	int maximum = -1;
	for(int i=0;i<n;i++){
		if(Nodes[i]->parent ==NULL){
			groupCnt++;
			if(maximum<Nodes[i]->level){
				maximum = Nodes[i]->level;
			}
		}
	}
	cout<<groupCnt<<endl;
	cout<<maximum;
    return 0;
	
}