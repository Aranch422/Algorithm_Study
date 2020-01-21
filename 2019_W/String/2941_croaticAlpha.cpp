#include <iostream>
#include <string>

using namespace std;

int main(){
    int cnt=0;
    string s;
    cin>>s;
    string list[8]={"c=","c-","dz=","d-","lj","nj","s=","z="};
    int size =s.size();
    for(int i=0;i<size;){
        bool flag =true;
        string temp;
        temp=s[i];
        if(i<size-1) temp.push_back(s[i+1]);
        for(int j=0;j<8;j++){
            if(temp==list[j]){
                cnt++;
                i=i+2;
                flag=false;
                break;
            }
        }
        if(flag){
            temp.push_back(s[i+2]);
            for(int j=0;j<8;j++){
                if(temp==list[j]){
                    cnt++;
                    i=i+3;
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            i=i+1;
            cnt++;
        }

    }
    cout<<cnt;
    return 0;
}