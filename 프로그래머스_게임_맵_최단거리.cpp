#include<vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

void PushAbleIndex(int index,int jndex,int visit[][100],int n,int m,vector<vector<int> > &maps,queue<pair<int,int> > &q){
    int new_index,new_jndex;
    for(int i=0;i<4;i++){
        new_index="0121"[i]-'1'+index;
        new_jndex="1210"[i]-'1'+jndex;
    if(new_index>=0 && new_index<n && new_jndex >=0 && new_jndex <m && visit[new_index][new_jndex]==0 && maps[new_index][new_jndex]==1){
        q.push({new_index,new_jndex});
        visit[new_index][new_jndex]+=visit[index][jndex]+1;
        }
    }
}
int BFS(int visit[][100],int n ,int m,vector<vector<int> > &maps){
    queue <pair<int,int>> q;
    q.push({0,0});
    visit[0][0]=1;
    int cnt=0;
    while(!q.empty()){
        pair<int,int> info=q.front();
        q.pop();
        PushAbleIndex(info.first,info.second,visit,n,m,maps,q);
    }
    cout<<visit[n-1][m-1];
    return visit[n-1][m-1];
}
int solution(vector<vector<int> > maps)
{
    int n=maps.size();
    int m=maps[0].size();
    int visit[100][100]={0};
    int answer = BFS(visit,n,m,maps);
    if(answer==0)
        return -1;
    return answer;
}
