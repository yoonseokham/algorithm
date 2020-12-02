#include<vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> Point;
void FromCurrentPointVisitReachableIndex(Point current,int visit[][100],vector<vector<int> > &maps,queue<pair<int,int> > &q){
    int index=current.first,jndex=current.second,n=maps.size(),m=maps[0].size();
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
int BFS(int n ,int m,vector<vector<int> > &maps){
    queue <Point> q;
    int visit[100][100]={0};
    q.push({0,0});
    visit[0][0]=1;
    while(!q.empty()){
        Point info=q.front();
        q.pop();
        FromCurrentPointVisitReachableIndex(info,visit,maps,q);
    }
    return visit[n-1][m-1]==0?-1:visit[n-1][m-1];
}
int solution(vector<vector<int> > maps)
{
    return BFS(maps.size(),maps[0].size(),maps);
}
