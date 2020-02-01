#include <iostream>
#include <stack>
#include <math.h>
#include <vector>

using namespace std;

int n;

int HeapL[100001];
int sizeL=0;
int median;
int HeapR[100001];
int sizeR=0;

void init(){
    cin>>n;
    int num;
    cin>>num;
    median=num;
    n--;
}

void insertL(int num){
    sizeL++;
    HeapL[sizeL]=num;
    int idx=sizeL;
    while(idx/2>0){
        int parent=idx/2;
        if(HeapL[parent]<HeapL[idx]){
            int temp = HeapL[parent];
            HeapL[parent]=HeapL[idx];
            HeapL[idx]=temp;
            idx=parent;
        }
        else break;
    }
}

void insertR(int num){
    sizeR++;
    HeapR[sizeR]=num;
    int idx=sizeR;
    while(idx/2>0){
        int parent=idx/2;
        if(HeapR[parent]>HeapR[idx]){
            int temp = HeapR[parent];
            HeapR[parent]=HeapR[idx];
            HeapR[idx]=temp;
            idx=parent;
        }
        else break;
    }
}

void deleteL(){
    HeapL[1]=HeapL[sizeL];
    sizeL--;
    int idx=1;
    while(idx*2<=sizeL){
        int left=idx*2;
        int right=idx*2+1;

        //both children
        if(right<=sizeL){

            //left <right
            if(HeapL[left]<HeapL[right]){
                //parent<right
                if(HeapL[idx]<HeapL[right]){
                    int temp= HeapL[idx];
                    HeapL[idx]=HeapL[right];
                    HeapL[right]=temp;
                    idx=right;
                }
                else break;
            }
            else{
                if(HeapL[idx]<HeapL[left]){
                    int temp= HeapL[idx];
                    HeapL[idx]=HeapL[left];
                    HeapL[left]=temp;
                    idx=left;
                }
                else break;            
            }
        }

        else{
            if(HeapL[idx]<HeapL[left]){
                int temp= HeapL[idx];
                HeapL[idx]=HeapL[left];
                HeapL[left]=temp;
                idx=left;
            }
            else break;    
        }
    }
}

void deleteR(){
    HeapR[1]=HeapR[sizeR];
    sizeR--;
    int idx=1;
    while(idx*2<=sizeR){
        int left=idx*2;
        int right=idx*2+1;

        //both children
        if(right<=sizeR){

            //left <right
            if(HeapR[left]>HeapR[right]){
                //parent<right
                if(HeapR[idx]>HeapR[right]){
                    int temp= HeapR[idx];
                    HeapR[idx]=HeapR[right];
                    HeapR[right]=temp;
                    idx=right;
                }
                else break;
            }
            else{
                if(HeapR[idx]>HeapR[left]){
                    int temp= HeapR[idx];
                    HeapR[idx]=HeapR[left];
                    HeapR[left]=temp;
                    idx=left;
                }
                else break;            
            }
        }

        else{
            if(HeapR[idx]>HeapR[left]){
                int temp= HeapR[idx];
                HeapR[idx]=HeapR[left];
                HeapR[left]=temp;
                idx=left;
            }
            else break;    
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    while(n>0){
        //output check
        /*
        cout<<"HEAP L: ";
        for(int i=1;i<=sizeL;i++){
            cout<<HeapL[i]<<" ";
        }
        cout<<"\nMedian: "<<median<<"\nHEAP R: ";
        for(int i=1;i<=sizeR;i++){
            cout<<HeapR[i]<<" ";
        }
        cout<<endl;
        */
        cout<<median<<"\n";
        n--;
        int num;
        cin>>num;
        if(num<median){
            insertL(num);
        }
        else insertR(num);

        if(sizeR-sizeL>1){
            insertL(median);
            median=HeapR[1];
            deleteR();
        }
        else if(sizeL-sizeR>=1){
            insertR(median);
            median=HeapL[1];
            deleteL();
        }
    }
    cout<<median<<"\n";
    return 0;
}