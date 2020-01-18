#include <iostream>

using namespace std;

int H,W,N;

void init(){
    cin>>H>>W>>N;
}

int main(){
    int k;
    cin>> k;
    while(k>0){
        k--;
        init();
        int story, room;
        int ans;
        room=(N-1)/H+1;
        story=N%H;
        if(story==0) story+=H;
        if(room>=10){
            cout<<story<<room<<endl;
        }
        else{
            cout<<story<<0<<room<<endl;
        }
        
    }    
    return 0;
}