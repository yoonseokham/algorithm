#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define INF 2147483647
#define MAX 20001

using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
vector <pair<int,int> > v[MAX];
int dist[MAX]={0};
void Dijkstra(int vertex,int start){
  pq.push({0,start});
  while(!pq.empty()){
    int cur_node=pq.top().second;
    int cur_cost=pq.top().first;
    pq.pop();
    for(int i=0;i<v[cur_node].size();i++){
      int visitAbleNode=v[cur_node].at(i).first;
      int NewCost=v[cur_node].at(i).second;
      if(dist[visitAbleNode]>NewCost+dist[cur_node]){
        dist[visitAbleNode]=NewCost+dist[cur_node];
        pq.push({dist[visitAbleNode],visitAbleNode});
      }
    }
  }
}
int main(void){
  fill(dist,dist+MAX,INF);
  int vertex,edge,start,memo[3];
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>vertex>>edge>>start;
  for(int i=0;i<edge;i++){
    bool same=false;
    cin>>memo[0]>>memo[1]>>memo[2];
    for(int i=0;i<v[memo[0]].size();i++)
    {
      if(v[memo[0]].at(i).first==memo[1]){
          same=true;
          if(v[memo[0]].at(i).second>memo[2])
            v[memo[0]].at(i).second=memo[2];
        break;
      }
    }
    if(!same)
      v[memo[0]].push_back(make_pair(memo[1],memo[2]));
  }
  dist[start]=0;
  Dijkstra(vertex,start);
  for(int i=1;i<=vertex;i++){
    if(dist[i]==INF)
      cout<<"INF"<<"\n";
    else
      cout<<dist[i]<<"\n";
  }
  return 0;
}
