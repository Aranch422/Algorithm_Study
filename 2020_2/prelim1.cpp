#include <iostream>

using namespace std;

int n,k;

int num[1001];
int maxlen[1001];
int minlen[1001];
int maxInt[1001];
int minInt[1001];

int main(){
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>num[i];

    }

    for(int i=0;i<n;i++){
        maxlen[i]=0;
        minlen[i]=0;

        if(num[i]>1){
            maxInt[i]=num[i];
            maxlen[i]=1;
            minInt[i]=1;
            minlen[i]=0;
        }
        else{
            maxInt[i]=1;
            maxlen[i]=0;
            minInt[i]=num[i];
            minlen[i]=1;
        }

        for(int j=0;j<i;j++){
            if(num[j]<=num[i]){
                //nondecreasing
                if(maxInt[j]*num[i]>maxInt[i]){
                    if(maxlen[j]<k){
                        maxlen[i]=maxlen[j]+1;
                        maxInt[i]=maxInt[j]*num[i];
                    }
                }
                else if(maxInt[j]*num[i]<minInt[i]){
                    if(maxlen[j]<k){
                        minlen[i]=maxlen[j]+1;
                        minInt[i]=maxInt[j]*num[i];
                    }

                }
                else if(minInt[j]*num[i]>maxInt[i]){
                    if(minlen[j]<k){
                        maxlen[i]=minlen[j]+1;
                        maxInt[i]=minInt[j]*num[i];
                    }
                }
                else if(minInt[j]*num[i]<minInt[i]){
                    if(minlen[j]<k){
                        minlen[i]=minlen[j]+1;
                        minInt[i]=minInt[j]*num[j];
                    }
                }
            }
        }
    }

    int mymax=1;

    for(int i=0;i<n;i++){
        if(maxInt[i]>mymax){
            mymax=maxInt[i];
        }
    }
    cout<<mymax;
    /*
    for(int i=0;i<n;i++){
        cout<<"maxlen"
    }
    */


    return 0;
}