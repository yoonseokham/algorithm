#include <iostream>
#include <queue>
#define MAX 12
using namespace std;
priority_queue< int, vector<int>, greater<int> > q;
bool visited[MAX]={0};//i를 방문 했는지 안했는지 확인하는 배열 > start바뀔때마다 초기화해야함
int graph[MAX][MAX]={0};
int sum=0;
bool AllVisited(int size_arr){
  for(int i=1;i<=size_arr;i++){
    if(visited[i]==0)
      return false;
  }
  return true;
}

void DFS_BackTranking(const int size_arr,const int startNode=1, int currentNode=1,int cnt=0){
if(cnt==size_arr&&startNode==currentNode){
  q.push(sum+graph[currentNode][startNode]);
  return;
}
  for(int i=1;i<=size_arr;i++){
    if(!visited[i]&&graph[currentNode][i]!=0){
      visited[i]=true;
      sum+=graph[currentNode][i];
      DFS_BackTranking(size_arr,startNode,i,cnt+1);
      visited[i]=false;
      sum-=graph[currentNode][i];
    }
  }
}
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int size_arr=0;
  cin>>size_arr;
  for(int i=1;i<=size_arr;i++){
    for(int j=1;j<=size_arr;j++){
      cin>>graph[i][j];
    }
  }
for(int i=1;i<=size_arr;i++){
  DFS_BackTranking( size_arr,i,i);
  for(int j=1;j<=size_arr;j++){
    visited[j]=false;
  }
}
if(q.empty())
  cout<<"error";
else{
  cout<<q.top();
}
return 0;
}
