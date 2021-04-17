#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 200002
using namespace std;

int parent[MAX]={0};
typedef struct _Point{
  int weight;
  int start;
  int end;
}Point;
vector <pair <int,int> > v[MAX];
vector <Point> e;
int find(int x){
  if(parent[x]==x)
    return x;
  else
    return parent[x]=find(parent[x]);
}
bool unionAble(int i,int j){
  i=find(i);
  j=find(j);
  if(i==j)
    return false;
  else if(i<j){
      parent[j]=i;
    return true;
  }
  else {
    parent[i]=j;
  return true;
  }
}
bool cmp(const Point&a,const Point &b){
  if(a.weight<b.weight)
    return true;
  else
    return false;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int vertex,edge,weight,n=0,sum=0,start,end;
  Point a;
  while(cin>>vertex>>edge){
    sum=0,n=0;
  if(vertex==0&&edge==0)
    break;
  for(int i=0;i<MAX;i++){
      parent[i]=i;
      v[i].clear();
  }
  e.clear();
  for(int i=0;i<edge;i++){
    cin>>start>>end>>weight;
    v[start].push_back(make_pair(end,weight));
    v[end].push_back(make_pair(start,weight));
    a.weight=weight;
    a.start=start<end?start:end;
    a.end=start<end?end:start;
    e.push_back(a);
    sum+=weight;
  }
  sort(e.begin(),e.end(),cmp);
  while(n<e.size()){
    if(unionAble(e[n].start,e[n].end)){
      sum-=e[n].weight;
    }
      n++;
  }
  cout<<sum<<"\n";
}
  return 0;
}
