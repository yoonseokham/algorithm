#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 150000
using namespace std;
int visit[MAX]={0};
bool segCheck(int i){
  if(i>=0 &&i<MAX) return true;
  return false;
}
int BFS(int start,int end){
  vector <int> answer;
  priority_queue <pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int>> > q;
  int cur;
  for(int i=0;i<MAX;i++){
    visit[i]=-1;
  }
  visit[start]=0;
  q.push({0,start});
  while(!q.empty()){
    cur=q.top().second;
    q.pop();
    if(segCheck(cur-1)&&(visit[cur-1]>visit[cur]||visit[cur-1]==-1)){
      visit[cur-1]=visit[cur]+1;
      q.push({visit[cur-1],cur-1});
    }
    if(segCheck(cur+1)&&(visit[cur+1]>visit[cur]||visit[cur+1]==-1)){
      visit[cur+1]=visit[cur]+1;
      q.push({visit[cur+1],cur+1});

    }
    if(segCheck(cur*2)&&(visit[cur*2]>visit[cur]||visit[cur*2]==-1)){
      visit[cur*2]=visit[cur];
      q.push({visit[2*cur],cur*2});
    }
  }
  // for(int i=0;i<=8;i++)
  //   cout<<visit[i]<<" ";
  return visit[end];
}
int main(void){
  int k,n;
  cin>>k>>n;
  cout<<BFS(k,n);

  return 0;
}
