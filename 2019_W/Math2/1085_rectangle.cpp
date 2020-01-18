#include <iostream>

using namespace std;

int main(){
    int x, y, w, h;
    cin>>x>>y>>w>>h;
    int dx,dy;
    dx= (x<(w-x))? x:(w-x);
    dy= (y<(h-y))? y:(h-y);
    int ans = (dx<dy)? dx:dy;
    cout<< ans;

    return 0;
}