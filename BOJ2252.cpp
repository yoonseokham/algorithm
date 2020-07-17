#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;
vector < int > v[MAX];
queue <int > q;
int link[MAX]={0};
bool visited[MAX]={0};

bool allVisit(int n){
  for(int i=1;i<=n;i++){
      if(!visited[i])
        return false;
  }
  return true;
}
void TopologicalSort(int n){
  if(q.empty()&&allVisit(n))
    return;
  else if(q.empty()&&!allVisit(n)){
    for(int i=1;i<=n;i++){
      if(!visited[i]&&link[i]==0){
        q.push(i);
        visited[i]=true;
      }
    }
    TopologicalSort(n);
  }
  else{
    int topIndx=q.front();
    q.pop();
    cout<<topIndx<<" ";
  for(int i=0;i<v[topIndx].size();i++){
    if(!visited[v[topIndx][i]]&&link[v[topIndx][i]]==0)
      q.push(v[topIndx][i]);
      link[v[topIndx][i]]--;
    }
    TopologicalSort(n);
  }
}
int main(void){
  int n,m,temp1,temp2;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>temp1>>temp2;
    v[temp1].push_back(temp2);
    link[temp2]++;
  }
  for(int i=1;i<=n;i++){
    if(link[i]==0){
      q.push(i);
      visited[i]=true;
    }
  }
  TopologicalSort(n);
}
