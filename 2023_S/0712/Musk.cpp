#include <iostream>
#include <vector>
using namespace std;

struct node{
    int maxVal;
    int r;
    int c;
    bool isSafe;
    node(int m,int r, int c, bool b):maxVal(m),r(r),c(c),isSafe(b){}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;

    for(int testCnt = 1;testCnt<=t;testCnt++){
        int n,m,q;
        cin>>n>>m>>q;
        vector<node> maxInRow = vector<node>(n,node(-1,-1,-1,false));
        vector<node> maxInCol = vector<node>(m,node(-1,-1,-1,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val;
                cin>>val;

                if(maxInRow[i].maxVal<val){
                    maxInRow[i].maxVal = val;
                    maxInRow[i].r = i;
                    maxInRow[i].c = j;
                    maxInRow[i].isSafe =false;
                }
                if(maxInCol[j].maxVal<val){
                    maxInCol[j].maxVal = val;
                    maxInCol[j].r = i;
                    maxInCol[j].c = j;
                    maxInCol[j].isSafe =false;
                }
            }
        }

        int safeCnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maxInRow[i].maxVal == maxInCol[j].maxVal){
                    maxInRow[i].isSafe = true;
                    maxInCol[j].isSafe = true;
                    safeCnt++;
                    break;
                }
            }
        }

        int sumOfSafeCnt = 0;
        while(q-->0){
            int r,c,val;
            cin>>r>>c>>val;
            r--;
            c--;
            if(maxInRow[r].maxVal<val){
                if(maxInCol[c].maxVal<val){
                    if(maxInRow[r].isSafe ==true && maxInCol[c].isSafe == true){
                        if(maxInCol[c].maxVal == maxInRow[r].maxVal){

                        }
                        else{
                            int pastRow = maxInCol[c].r;
                            maxInRow[pastRow].isSafe =false;
                            int pastCol = maxInRow[r].c;
                            maxInCol[pastCol].isSafe =false;
                            safeCnt--;
                        }
                    }
                    else if(maxInRow[r].isSafe == true){
                        int pastCol = maxInRow[r].c;
                        maxInCol[pastCol].isSafe =false;

                    }
                    else if(maxInCol[c].isSafe == true){
                        int pastRow = maxInCol[c].r;
                        maxInRow[pastRow].isSafe =false;

                    }
                    else{
                        safeCnt++;
                    }
                
                    
                    maxInCol[c].maxVal = val;
                    maxInCol[c].r = r;
                    maxInCol[c].c = c;
                    maxInCol[c].isSafe = true;

                    maxInRow[r].isSafe = true;
                    maxInRow[r].maxVal=val;
                    maxInRow[r].r = r;
                    maxInRow[r].c = c;
                    
                }
                else{
                    if(maxInRow[r].isSafe ==true){
                        int pastCol = maxInRow[r].c;
                        maxInCol[pastCol].isSafe = false;
                        safeCnt--;
                    }
                    maxInRow[r].maxVal=val;
                    maxInRow[r].r = r;
                    maxInRow[r].c = c;
                    maxInRow[r].isSafe = false;
                }
            }
            else if(maxInCol[c].maxVal<val){
                if(maxInCol[c].isSafe ==true){
                    int pastRow = maxInCol[c].r;
                    maxInRow[pastRow].isSafe =false;
                    safeCnt--;
                }
                maxInCol[c].maxVal = val;
                maxInCol[c].r = r;
                maxInCol[c].c = c;
                maxInCol[c].isSafe = false;
            }
            sumOfSafeCnt += safeCnt;
            //cout<<safeCnt<<endl;
        }
        cout<<"#"<<testCnt<<" "<<sumOfSafeCnt<<"\n";
    }
    return 0;
}