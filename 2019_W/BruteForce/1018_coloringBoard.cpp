#include <iostream>

using namespace std;

int M,N;
int num;
char board[50][50];
pair<int,int> mylist[1849];

void init(){
    cin>>M>>N;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
        }
    }
    num=(M-7)*(N-7);
    int k=0;
    for(int i=0;i<M-7;i++){
        for(int j=0;j<N-7;j++){
            mylist[k++]=make_pair(i,j);
        }
    }

}



int check(int r,int c){
    //check b w each

    int cnt1=0;
    int cnt2=0;
    //check b
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            //even
            if((i+j)%2==0){
                if(board[r+i][c+j]!='B') cnt1++;
            }
            else{
                if(board[r+i][c+j]!='W') cnt1++;
            }
        }
    }

    //white
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            //even
            if((i+j)%2==0){
                if(board[r+i][c+j]!='W') cnt2++;
            }
            else{
                if(board[r+i][c+j]!='B') cnt2++;
            }
        }
    }
    return (cnt1<cnt2)? cnt1:cnt2;
}


int main(){
    init();
    int min=65;
    for(int i=0;i<num;i++){
        int temp =check(mylist[i].first,mylist[i].second);
        if(min>temp) min=temp;
    }
    cout<< min<<endl;

    return 0;
}
