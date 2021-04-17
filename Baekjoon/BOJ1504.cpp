#include <iostream>
#include <queue>
#include <vector>
#define MAX 801
#define INF 2000000000
using namespace std;
vector < pair <int, int> > v[MAX];
int dp[MAX]={0};
priority_queue < pair <int ,int > > q;

bool same(int temp[]){
bool sameElement=false;
  for(int i=0;i<v[temp[0]].size();i++){
    if(v[temp[0]].at(i).first==temp[1]&&v[temp[0]].at(i).second>temp[2]){
      v[temp[0]].at(i).second=temp[2];
      sameElement=true;
    }
  }
  if(sameElement){
    for(int i=0;i<v[temp[1]].size();i++)
    if(v[temp[1]].at(i).first==temp[0]&&v[temp[1]].at(i).second>temp[2]){
      v[temp[1]].at(i).second=temp[2];
      return true;
    }
  }
  return false;
}
int minusI(int a){
  return -1*a;
}
void dijkstra(int n,int m,int start,int end,int &x){

while(!q.empty()){
  q.pop();
}
  for(int i=0;i<=n;i++)
    dp[i]=INF;
  dp[start]=0;
  for(int i=1;i<=n;i++)
    q.push({minusI(dp[i]),i});
  while(!q.empty()){
    int topindx=q.top().second;
    int topCost=minusI(q.top().first);
    q.pop();
    for(int i=0;i<v[topindx].size();i++){
      if(v[topindx].at(i).second+topCost<dp[v[topindx].at(i).first]){
        dp[v[topindx].at(i).first]=v[topindx].at(i).second+topCost;
        q.push({minusI(v[topindx].at(i).second+topCost),v[topindx].at(i).first});
      }
    }
  }
  x=dp[end];
}
int main(void){
  int n,m,temp[3],mid1,mid2,x,answer;
  int x1,x2;
  int y1,y2;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>temp[0]>>temp[1]>>temp[2];
    if(!same(temp)){
      v[temp[0]].push_back({temp[1],temp[2]});
      v[temp[1]].push_back({temp[0],temp[2]});
    }
  }
  cin>>mid1>>mid2;
  if(m==0){
    cout<<-1;
    return 0;
  }
  dijkstra(n,m,mid1,mid2,x);
  dijkstra(n,m,1,mid1,x1);
  dijkstra(n,m,mid2,n,x2);
  dijkstra(n,m,1,mid2,y1);
  dijkstra(n,m,mid1,n,y2);
  answer=min(x+x1+x2,x+y1+y2);
  if(answer>=INF||answer<=0)
    cout<<-1;
  else
    cout<<answer;//<<" ";
  //cout<<x+y1+y2;
  // for(int i=1;i<=n;i++){
  //   for(int j=0;j<v[i].size();j++)
  //     cout<<v[i].at(j).first<<" "<<v[i].at(j).second<<" ";
  //   cout<<"\n";
  // }
	return 0;
	}
