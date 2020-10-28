#include <iostream>

using namespace std;

void foo(int (&arr)[2]){
    arr[1]=0;
}

int main(){
    int arr[2]={1,2};
    foo(arr);
    cout<<arr[0]<<" "<<arr[1];

}