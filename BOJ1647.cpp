#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100002
using namespace std;
int parent[MAX]={0};
int last=0;
typedef struct _Point{
  int weight;
  int start;
  int end;
}Point;
vector<pair<int,int> > v[MAX];
vector<Point> e;
int find(int i){ //i의 루트를 찾는 함수
  if(parent[i]==i)
    return i;
  else{
    return parent[i] = find(parent[i]);
  }
}
void unionF(int x, int y) {
        x = find(x);
        y = find(y);
        // 같은 부모를 가지고 있지 않을 때
        if(x != y) {
            if(x < y) parent[y] = x;
            else parent[x] = y;
        }
    }
bool isSameParent(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y)
            return true;
        else
            return false;
    }
bool cmp(const Point &a,const Point &b){
  if(a.weight<b.weight)
    return true;
  else
    return false;
}
int main(void) {
ios_base::sync_with_stdio(false); cin.tie(NULL);
 int vertex,edge,start,end,weight,n=0,sum=0;
  cin>>vertex>>edge;
  for(int i=1;i<=MAX;i++){
    parent[i]=i;//자기자신을
  }
  for(int i=0;i<edge;i++){
    cin>>start>>end>>weight;
    v[start].push_back(make_pair(end,weight));
    v[end].push_back(make_pair(start,weight));
    Point a;
    a.weight=weight;
    a.start= start<end ? start:end;
    a.end=  start<end ? end:start;
    e.push_back(a);
  }
  sort(e.begin(),e.end(),cmp);
  while(n<e.size()){
    if(!isSameParent(e[n].start,e[n].end)){
      unionF(e[n].start,e[n].end);
      sum+=e[n].weight;
      last=e[n].weight;
    }
    n++;
  }
cout<<sum-last;
  return 0;
}
