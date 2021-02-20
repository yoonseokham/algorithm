#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visit[100001]={0};
queue <pair<int,int > > q;

int BFS(int n){
  pair<int,int> info;
  q.push(make_pair(n,0));
  while(!q.empty()){
    info=q.front();
    q.pop();
    if(info.first==1)
      return info.second;
    if(info.first<1)
      continue;
    if(info.first%2==0)
      q.push(make_pair(info.first/2,info.second+1));
    if(info.first%3==0)
      q.push(make_pair(info.first/3,info.second+1));
    q.push(make_pair(info.first-1,info.second+1));
  }
  return 0;
}
int main(void){
  int x;
  cin>>x;
  cout<<BFS(x);
  return 0;
}
