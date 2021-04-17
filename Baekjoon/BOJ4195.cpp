#include <iostream>
#include <string>
#include <unordered_map>
#define MAX 200002
using namespace std;
unordered_map <string,int> mapping;
int parent[MAX]={0};
int find(int x){
  if(x==parent[x])
    return x;
  else
    return parent[x]=find(parent[x]);
}
void unionXY(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y)
    return;
  else{
    if(y>x){
      parent[y]=x;
    }
    else if(y<x){
      parent[x]=y;
    }
  }
}
int deter_union_member(int x,int value){
int target_p=find(x),count=0;
  for(int i=0;i<=value;i++){
    if(target_p==find(i)){
      count++;
    }
  }
  return count;
}
void init_parent(){
  for(int i=0;i<MAX;i++){
    parent[i]=i;
  }
}
int main(void) {
  int n,m;
  string temp[2];
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>m;
    int value=1;
    mapping.clear();
    init_parent();
    for(int j=0;j<m;j++){
      cin>>temp[0]>>temp[1];
      if(mapping.find(temp[0])==mapping.end())
        mapping[temp[0]]=value++;
      if(mapping.find(temp[1])==mapping.end())
        mapping[temp[1]]=value++;
      unionXY(mapping[temp[0]],mapping[temp[1]]);
      cout<<deter_union_member(mapping[temp[0]],value)<<"\n";
    }
  }
  return 0;
}
