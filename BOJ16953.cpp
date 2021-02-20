#include <queue>
#include <vector>
#include <iostream>

using namespace std;
queue <pair<long long,long long> > q;
long long BFS(long long a,long long b){
  pair<long long,long long>  tmp;
  q.push(make_pair(a,0));
  while(!q.empty()){
    tmp=q.front();
    q.pop();
    if(tmp.first==b)  return tmp.second+1;
    if(tmp.first>b)
      continue;
    else{
      q.push(make_pair(2*tmp.first,tmp.second+1));
      q.push(make_pair(10*tmp.first+1,tmp.second+1));
    }
  }
  return -1;
}
int main(void){
  long long a,b;
  cin>>a>>b;
  cout<<BFS(a,b);
  return 0;
}
