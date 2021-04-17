#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <int> v[50];
int BFS(int n,int start){
  queue <int> q;
  q.push(start);
  int visit[50]={0},frontElement=0;
  visit[start]=1;
  while(!q.empty()){
    frontElement=q.front();
    q.pop();
    for(int i=0;i<v[frontElement].size();i++){
      if(visit[v[frontElement][i]]==0){
        visit[v[frontElement][i]]=visit[frontElement]+1;
        q.push(v[frontElement][i]);
      }
    }
  }
sort(visit+1,visit+n+1);
return visit[n];
}
int main(void){
  int n,temp[2];
  vector <pair<int,int> > candidate;
  cin>>n;
  while(true){
    cin>>temp[0]>>temp[1];
    if(temp[0]==-1)
      break;
    v[temp[0]].push_back(temp[1]);
    v[temp[1]].push_back(temp[0]);
  }
  for(int i=1;i<=n;i++)
    candidate.push_back({BFS(n,i),i});
  sort(candidate.begin(),candidate.end());
  cout<<candidate[0].first-1<<" ";
  int cnt=1;
  for(int i=0;i<n-1;i++){
    if(candidate[i].first==candidate[i+1].first)
      cnt++;
    else
      break;
  }
  cout<<cnt<<"\n";
  for(int i=0;i<cnt;i++)
    cout<<candidate[i].second<<" ";
  return 0;
}
