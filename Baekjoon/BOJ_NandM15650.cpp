//BOJ N과M (2) 15650번
#include <iostream>
#include <vector>
#define MAX 9
using namespace std;
vector<int> v;
bool visited[MAX]={0};
bool check[MAX]={0};
void nCm_back_track(int start,int n,int m,int cnt=0){
  if(cnt==m){
    for(int i=0;i<v.size();i++){
      cout<<v.at(i)<<" ";
    }
    cout<<"\n";
  return;
  }
  for(int i=start;i<=n;i++){
    if(!visited[i]){
    visited[i]=true;
    v.push_back(i);
    nCm_back_track(i+1,n,m,cnt+1);
    v.pop_back();
    visited[i]=false;
  }
  }
}
int  main(void){
  int n,m;
  cin>>n>>m;
nCm_back_track(1,n,m);
  return 0;
}
