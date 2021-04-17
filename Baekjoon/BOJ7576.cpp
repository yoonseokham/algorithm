#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int arr[1000][1000]={0};
int visit[1000][1000]={0};
queue < pair < int , int > > q;
bool SegCheck(int i,int j,int n,int m){
  if(i>=0 &&i<n &&j>=0 && j<m)  return true;
  return false;
}
int BFS(int n,int m){
  pair<int,int> topElement;
  int NewI,NewJ,Max=-1;
  while(!q.empty()){
    topElement=q.front();
    q.pop();
    for(int i=0;i<4;i++){
      NewI=topElement.first+"0121"[i]-'1';
      NewJ=topElement.second+"1210"[i]-'1';
      if(SegCheck(NewI,NewJ,n,m) && visit[NewI][NewJ]== -1 && arr[NewI][NewJ] == 0){
        visit[NewI][NewJ]=visit[topElement.first][topElement.second]+1;
        q.push({NewI,NewJ});
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(visit[i][j]==-1 && arr[i][j]==0)
        return -1;
      else
        Max=Max>visit[i][j]?Max:visit[i][j];
    }
  }
  return Max;
}
int main(void){
  int m,n;
  cin>>m>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>arr[i][j];
      if(arr[i][j]==0 || arr[i][j]==-1)
        visit[i][j]=-1;
      else {
        visit[i][j]=0;
        q.push({i,j});
      }
    }
  }
  cout<<BFS(n,m);
  return 0;
}
