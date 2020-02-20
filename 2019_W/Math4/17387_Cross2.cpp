#include <iostream>

using namespace std;

pair<long long,long long> point[5];

void init(){
    for(long long i=1;i<5;i++){
        long long x,y;
        cin>>x>>y;
        point[i]=make_pair(x,y);
    }
    if(point[1].first>point[2].first){
        pair<long,long> temp;
        temp=point[2];
        point[2]=point[1];
        point[1]=temp;
    }
    if(point[3].first>point[4].first){
        pair<long,long> temp;
        temp=point[4];
        point[4]=point[3];
        point[3]=temp;
    }
}

int ccw(long long a,long long b,long long c){
    pair<long long,long long> vec1,vec2;
    vec1.first=point[b].first-point[a].first;
    vec1.second=point[b].second-point[a].second;
    vec2.first=point[c].first-point[a].first;
    vec2.second=point[c].second-point[a].second;
    long long cross=vec1.first*vec2.second-vec1.second*vec2.first;
    if(cross>0) return 1;
    else if(cross==0) return 0;
    else return -1;
}

int main(){
    init();
    // 3 point 1 line
    if(ccw(1,2,3)==0){
        if(point[1].first<=point[3].first&&point[3].first<=point[2].first){
            cout<<1;
            return 0;
        }
        else{
            if(ccw(1,2,4)==0){
                if(point[1].first<=point[4].first&&point[4].first<=point[2].first){
                    cout<<1;
                    return 0;
                }
                else cout<<0;
                return 0;
            }
            else cout<<0;
            return 0;
        }
    }
    else if(ccw(1,2,4)==0){
        if(point[1].first<=point[4].first&&point[4].first<=point[2].first){
            cout<<1;
            return 0;
        }
        else cout<<0;
        return 0;
    }

    //no 3point 1line
    else if(ccw(1,2,3)*ccw(1,2,4)<0){
        if(ccw(3,4,1)==0){
            if(point[3].first<=point[1].first&&point[1].first<=point[4].first){
                cout<<1;
                return 0;
            }
            else{
                if(ccw(3,4,2)==0){
                    if(point[3].first<=point[2].first&&point[2].first<=point[4].first){
                        cout<<1;
                        return 0;
                    }
                    else cout<<0;
                }
                else cout<<0;
                return 0;
            }
        }
        else if(ccw(3,4,2)==0){
            if(point[3].first<=point[2].first&&point[2].first<=point[4].first){
                cout<<1;
                return 0;
            }
            else cout<<0;
            return 0;
        }
        else if(ccw(3,4,1)*ccw(3,4,2)<0) cout<<1;
        else cout<<0;
    }
    else cout<<0;

    return 0;
}