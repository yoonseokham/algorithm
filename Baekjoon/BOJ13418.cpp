#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> nodeInfo;
int parent[1001]={0};
vector <pair<int,nodeInfo> > v;

void init_parent(int n){
  for(int i=0;i<n+1;i++){
    parent[i]=i;
  }
  return;
}
int find(int x){
  if(parent[x]==x) return x;
  else return parent[x]=find(parent[x]);
}
bool unionXY(int x,int y){
  x=find(x),y=find(y);
  if(x==y)  return false;
  else if(x<y) parent[y]=x;
  else parent[x]=y;
  return true;
}
bool allConnected(int n){
  for(int i=0;i<n;i++){
    if(find(i)!=find(i+1)) return false;
  }
  return true;
}
int main(void){

  int n,m,start,end,cost,i=0,min=0,max=0;
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>n>>m;
  for(int i=0;i<=m;i++){
    cin>>start>>end>>cost;
    if(cost==0) v.push_back({1,{start,end}});
    else v.push_back({0,{start,end}});

  }
  init_parent(n);
  sort(v.begin(),v.end());
  while(!allConnected(n)){
    if(unionXY(v[i].second.first,v[i].second.second)) min+=v[i].first;
    i++;
  }
  init_parent(n);
  sort(v.begin(), v.end(), greater<pair<int,nodeInfo> >());
  i=0;
  while(!allConnected(n)){
    if(unionXY(v[i].second.first,v[i].second.second)) max+=v[i].first;
    i++;
  }
  cout<<max*max-(min)*(min);
  return 0;
}
