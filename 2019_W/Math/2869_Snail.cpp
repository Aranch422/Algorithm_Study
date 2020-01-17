#include <iostream>

using namespace std;

int main(){
    int day,night,target;

    int ans=1;

    cin>>day>>night>>target;

    target-=day;
    if(target>0){
        ans+=target/(day-night);
        if(target%(day-night)!=0) ans++;
    }
    cout<< ans;

    return 0;
}