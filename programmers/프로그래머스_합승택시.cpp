#include <string>
#include <vector>
#include <queue>

#define MAX 2000000000
using namespace std;
void Dijkstra(int start,int dp[201],vector<pair<int,int> > v[201]){
    priority_queue< pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    int curNode,curCost;
    pair<int,int> temp;
    dp[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        temp=pq.top();
        pq.pop();
        curCost=temp.first,curNode=temp.second;
        if(curCost>dp[curNode]) continue;
        for(int i=0;i<v[curNode].size();i++){
            int candidateNode=v[curNode][i].first;
            int candidateNodeCost=v[curNode][i].second;
            if(curCost+candidateNodeCost<dp[candidateNode]){
                dp[candidateNode]=curCost+candidateNodeCost;
                pq.push({dp[candidateNode],candidateNode});
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = MAX;
    int startNode,endNode,cost;
    int dp[3][201];
    for(int j=0;j<3;j++)
        for(int i=0;i<201;i++) dp[j][i]=MAX;
    vector<pair<int,int> > v[201];
    for(int i=0;i<fares.size();i++){
        startNode=fares[i][0];
        endNode=fares[i][1];
        cost=fares[i][2];
        v[startNode].push_back({endNode,cost});
        v[endNode].push_back({startNode,cost});
    }
    Dijkstra(s,dp[0],v);
    Dijkstra(a,dp[1],v);
    Dijkstra(b,dp[2],v);
    answer=dp[0][a]+dp[0][b];
    for(int i=1;i<=n;i++) answer=min(answer,dp[0][i]+dp[1][i]+dp[2][i]);
    return answer;
}
