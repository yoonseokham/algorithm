#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
bool arr[MAX][MAX]={0};
queue<int> q;
bool visited[MAX]={0};
int BFS(int fromA,int toB,int numOfPeople){
  bool meet=false;
  int shortist=0,topElement;
  visited[fromA]=true;
  for(int i=1;i<=numOfPeople;i++){
    if(arr[fromA][i]){
      q.push(i);
      visited[i]=true;}
  }
int real=0;
  while(!q.empty()){
    int n=q.size();
    for(int i=0;i<n;i++){
      topElement=q.front();
      q.pop();
      if(topElement==toB){
        meet=true;
        real=shortist+1;
        //break;
      }
      for(int j=1;j<=numOfPeople;j++){
        if(arr[topElement][j]&&!visited[j]){
          q.push(j);
          visited[j]=true;
        }
      }
    }
    shortist++;
  }
  if(meet)
    return real;
  else
    return -1;
}
int main(void)
{
  int numOfPeople,fromA,toB,relation,tempMom,tempSun;
  cin>>numOfPeople;
  cin>>fromA>>toB;
  cin>>relation;
  for(int i=0;i<relation;i++){
    cin>>tempMom>>tempSun;
    arr[tempMom][tempSun]=true;
    arr[tempSun][tempMom]=true;
  }
    cout<<BFS(fromA,toB,numOfPeople);
  return 0;
}
/*  topElement=q.front();
  q.pop();
  if(topElement==toB){
    meet=true;
    break;
  }
  for(int j=1;j<=numOfPeople;j++){
    if(arr[topElement][j]&&visited[j]==false){
      q.push(j);
      visited[j]=true;}
    }
shortist++;*/
