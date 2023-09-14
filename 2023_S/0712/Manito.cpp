#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

const int INF = 987654321;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int graph[401][401];
    
    for(int testCnt=1;testCnt<=t;testCnt++){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                graph[i][j] = INF;
            }
        }
        for(int i=0;i<m;i++){
            int start,dest,cost;
            cin>>start>>dest>>cost;
            graph[start][dest] = cost;
        }

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
                }
            }
        }
        int lowestCost = INF;
        for(int i=1;i<=n;i++){
            if(graph[i][i]<lowestCost){
                lowestCost = graph[i][i];
            }
        }
        cout<<"#"<<testCnt<<" "<<lowestCost<<"\n";
    }
    return 0;
}

코테 연습 스터디 하실 분 있나요
알고리즘 공부말고 구현문제 빠르게 구현해내기를 목표로 합니다.

풀기전에 시간을 정해놓고
1. 실제로 시간내에 얼마나 구현했는지
2. 다 구현하는데 얼마나 걸렸는지
3. 왜 시간이 오래 걸렸는지 or 빨리 풀었는지
를 간단하게 적어서 제출합니다.

그리고 생각나는 팁들을 공동 팁 정리 파일에 같이 공유할 수 있게 할 생각입니다.

하루에 한 문제씩 일주일에 다섯 문제 목표로 합니다.
C++ 사용합니다.

방학동안 하실 분?