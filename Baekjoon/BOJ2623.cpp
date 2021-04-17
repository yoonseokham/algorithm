#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;
vector < int > v[MAX];
vector <int > result;
queue <int > q;
int link[MAX]={0};
bool visited[MAX]={0};
int arr[1001]={0};
bool fail=false;
bool sort_disable(int n){
  for(int i=1;i<=n;i++){
      if(visited[i]==false&&link[i]==0)
        return false;
  }
  return true;
}
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
    else if(sort_disable(n)&&q.empty()){
      fail=true;
      cout<<"0";
      return;
    }
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
    result.push_back(topIndx);//<<" ";
  for(int i=0;i<v[topIndx].size();i++){
    if(!visited[v[topIndx][i]]&&link[v[topIndx][i]]==0)
      q.push(v[topIndx][i]);
      link[v[topIndx][i]]--;
    }
    TopologicalSort(n);
  }
}
int main(void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n,m,temp1;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>temp1;
    for(int j=0;j<temp1;j++)
      cin>>arr[j];
    for(int k=0;k<temp1-1;k++){
      v[arr[k]].push_back(arr[k+1]);
      link[arr[k+1]]++;
    }
  }
  if(sort_disable(n)){
    cout<<"0";
      return 0;
    }
  for(int i=1;i<=n;i++){
    if(link[i]==0){
      q.push(i);
      visited[i]=true;
    }
  }
  TopologicalSort(n);
  if(!fail){
  for(int i=0;i<result.size();i++)
    cout<<result[i]<<"\n";
  }
  return 0;
}
