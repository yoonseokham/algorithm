#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
int parent[MAX]={0};
typedef struct _node{
  int start;
  int end;
  int weight;
}Node;
bool cmp(const Node&a,const Node&b){
  if(a.weight>b.weight)
    return true;
  else
    return false;
}
vector<Node> sorted;
int find(int x){
  if(parent[x]==x)
    return x;
  else
    return parent[x]=find(parent[x]);
}
bool unionAble(int x,int y){
  x=find(x);
  y=find(y);

  if(x==y)
    return false;
  else
    return true;
}
void unionTogeter(int x,int y){
  x=find(x);
  y=find(y);

  if(x==y)
    return;
  else if(x>y)
    parent[x]=y;
  else
    parent[y]=x;
  return;
}
bool parentSame(int start,int end){
  start=find(start);
  end=find(end);
  if(start==end)
    return true;
  else
    return false;
}
int main(void){
  int sum=0,l=0;
  for(int i=0;i<MAX;i++)
    parent[i]=i;
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m,start,end;
  int temp1,temp2,weight;
  cin>>n>>m>>start>>end;
  for(int i=0;i<m;i++){
    Node temp;
    cin>>temp1>>temp2>>weight;
    temp.start=temp1;
    temp.end=temp2;
    temp.weight=weight;
    sorted.push_back(temp);
  }
  sort(sorted.begin(),sorted.end(),cmp);
while(l<sorted.size()){
  if(parentSame(start,end))
    break;
  if(unionAble(sorted[l].start,sorted[l].end)){
    unionTogeter(sorted[l].start,sorted[l].end);
    sum=sorted[l].weight;
  }
  l++;
}
if(parentSame(start,end))
    cout<<sum;
else
  cout<<0;
  return 0;
}
