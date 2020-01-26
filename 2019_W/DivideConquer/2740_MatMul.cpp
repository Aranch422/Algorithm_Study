#include <iostream>

using namespace std;

int mat1[100][100];
int mat2[100][100];
int ret[100][100];

int r1,c1,r2,c2;

void init(){
    cin>>r1>>c1;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin>>mat1[i][j];
        }
    }

    cin>>r2>>c2;
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin>>mat2[i][j];
        }
    }
}

void Matmul(){
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            int temp=0;
            for(int k=0;k<c1;k++){
                temp+=mat1[i][k]*mat2[k][j];
            }
            ret[i][j]=temp;
        }
    }
}

int main(){
    init();
    Matmul();
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            cout<< ret[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}