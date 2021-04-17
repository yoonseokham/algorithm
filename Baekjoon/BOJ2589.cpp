#include <iostream>
#include <algorithm>
#include <vector>;
#include<cstdio>
#include <queue>
#define MAX 52
using namespace std;
int rows,cols,maxd=0;
queue <pair <int, int> > q;
int arr[MAX][MAX]={0};
int visited[MAX][MAX]={0};
void BFS(int indx,int jndx){
q.push(make_pair(indx,jndx));
int hour=0,n=q.size();
visited[indx][jndx]=1;
  int di[4]={-1,0,1,0};
  int dj[4]={0,1,0,-1};
  while(!q.empty()){
    for(int j=0;j<n;j++){
      indx= q.front().first;
      jndx= q.front().second;
      q.pop();
      for(int i=0;i<4;i++){
        if(!visited[indx+di[i]][jndx+dj[i]]&&arr[indx+di[i]][jndx+dj[i]]=='L'){
            visited[indx+di[i]][jndx+dj[i]]=visited[indx][jndx]+1;
            q.push(make_pair(indx+di[i],jndx+dj[i]));
          }
        }
    }
  }
  hour=visited[indx][jndx]-1;
  maxd=max(maxd,hour);
}
void init(void){
  for(int i=1;i<=rows;i++){
    for(int j=1;j<=cols;j++){
      visited[i][j]=0;
    }
  }
}
void dfsStarter(void){
  for(int i=1;i<=rows;i++){
    for(int j=1;j<=cols;j++){
      if(arr[i][j]=='L'){
          BFS(i,j);
          init();
      }
    }
  }
}
int main(void){
cin>>rows>>cols;
fgetc(stdin);
  for(int i=0;i<MAX;i++){
    for(int j=0;j<MAX;j++){
      arr[i][j]='W';
    }
  }
  for(int i=1;i<=rows;i++){
    for(int j=1;j<=cols;j++){
      arr[i][j]=fgetc(stdin);
    }
    fgetc(stdin);
  }
  dfsStarter();
  cout<<maxd;
  return 0;
}
