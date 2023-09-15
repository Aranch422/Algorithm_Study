#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

struct Person{
    int num;
    int skill;
};

bool cmp(Person& a, Person& b){
    return a.skill<b.skill;
}

Person people[100000];
int dp[100000][4];
vector<int> dead[100000][4];

int GetSkiilDiff(int now, int remain){
    if(now >=N-3){
        return 0;
    } 
    if(dp[now][remain] != -1){
        return dp[now][remain];
    }

    int ans0 = people[now+3].skill - people[now].skill  + GetSkiilDiff(now+4,remain);
    int ans1, ans2,ans3;
    int myMin = ans0;
    int skipNum = 0;
    if(remain >= 1){
        ans1 = GetSkiilDiff(now+1,remain-1);
        if(ans1 < myMin){
            myMin = ans1;
            skipNum = 1;
        }
    }
    if(remain >= 2){
        ans2 = GetSkiilDiff(now+2,remain-2);
        if(ans2 < myMin){
            myMin = ans2;
            skipNum = 2;
        }
    }
    if(remain >= 3){
        ans3 = GetSkiilDiff(now+3,remain-3);
        if(ans3 < myMin){
            myMin = ans3;
            skipNum = 3;
        }
    }
    dp[now][remain] = myMin;
    if(skipNum == 0){
        dead[now][remain] = dead[now+4][remain-skipNum];
    }
    else{
        dead[now][remain] = dead[now+skipNum][remain-skipNum];
    }

    for(int i=0;i<skipNum;i++){
        dead[now][remain].push_back(people[now+i].num);
    }
    return dp[now][remain];
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        people[i].num = i;
        cin>>people[i].skill;

        for(int j=0;j<4;j++){
            dp[i][j] = -1;
        }
    }
    sort(people,people+N,cmp);

    int rem = N%4;
    cout<<GetSkiilDiff(0,rem)<<endl;
    for(int item : dead[0][rem]){
        cout<<item<<endl;
    }
    if(dead[0][rem].size()<rem){
        int temp = rem - dead[0][rem].size();
        for(int i= 0;i<temp;i++){
            cout<<people[N-1-i].num<<endl;
        }
    }
    return 0;
}