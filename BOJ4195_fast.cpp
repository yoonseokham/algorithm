#include <iostream>
#include <string>
#include <map>
#define MAX 200002

using namespace std;

map<string,int> mapping;
int parent[MAX]={0};
int level[MAX]={0};
void init_array(void){
  for(int i=0;i<MAX;i++)
  {
    parent[i]=i;
    level[i]=1;
  }
}
int find(int x){
  if(parent[x]==x)
    return x;
  else
    return parent[x]=find(parent[x]);
}
void unionXY(int x,int y){
  x=find(x);
  y=find(y);
  if(x!=y){
    if(x<y){
      parent[y]=x;
      level[x]+=level[y];
      // cout<<level[x]<<"\n";
    }
    else if(x>y){
      parent[x]=y;
      level[y]+=level[x];
      // cout<<level[y]<<"\n";
    }
  }
}
int main(void){
int n,m,value;
string temp[2];
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>m;
    value=1;
    init_array();
    for(int j=0;j<m;j++){
      cin>>temp[0]>>temp[1];
      if(mapping.find(temp[0])==mapping.end())
        mapping[temp[0]]=value++;
      if(mapping.find(temp[1])==mapping.end())
        mapping[temp[1]]=value++;
      unionXY(mapping[temp[0]],mapping[temp[1]]);
      cout<<level[find(mapping[temp[0]])]<<"\n";
    }
  }
  return 0;
}
