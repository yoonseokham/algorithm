#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue <pair<int,int> > WaterQ;
queue <pair<int,int> > RatQ;
int arr[51][51]={0};
int visit[51][51]={0};
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
bool visit_able(int i,int j,int n,int m){
  if(i<0||j<0||i>=n||j>=m)
    return false;
  return true;
}
void BFS(int n,int m){
  int size_water,size_rat=1,count=0;
  pair <int,int> temp_water_location,temp_rat_location;
while(!WaterQ.empty()||!RatQ.empty()){
    count++;
    size_rat=RatQ.size();
    size_water=WaterQ.size();
    for(int i=0;i<size_rat;i++){
      temp_rat_location=RatQ.front();
      RatQ.pop();
      if(visit[temp_rat_location.first][temp_rat_location.second]=='*')
        continue;
      for(int j=0;j<4;j++){
        int temp_i,temp_j;
        temp_i=temp_rat_location.first+di[j];
        temp_j=temp_rat_location.second+dj[j];
        if(visit_able(temp_i,temp_j,n,m)){
          if(visit[temp_i][temp_j]=='.'){
            RatQ.push({temp_i,temp_j});
            visit[temp_i][temp_j]='S';
          }
          else if(visit[temp_i][temp_j]=='D'){
            cout<<count;
            return;
          }
        }
      }
    }
    for (int i=0;i<size_water;i++){
      temp_water_location=WaterQ.front();
      WaterQ.pop();
      for(int j=0;j<4;j++){
        int temp_i,temp_j;
        temp_i=temp_water_location.first+di[j];
        temp_j=temp_water_location.second+dj[j];
        if(visit_able(temp_i,temp_j,n,m)){
          if(visit[temp_i][temp_j]=='.'||visit[temp_i][temp_j]=='S'){
            WaterQ.push({temp_i,temp_j});
            visit[temp_i][temp_j]='*';
          }
        }
      }
    }
  }
  cout<<"KAKTUS";
  return;
}
int main(void){
  int n,m;
  cin>>n>>m;
  fgetc(stdin);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      arr[i][j]=fgetc(stdin);
      visit[i][j]=arr[i][j];
      if(arr[i][j]=='*')
        WaterQ.push({i,j});
      else if(arr[i][j]=='S')
        RatQ.push({i,j});
    }
    fgetc(stdin);
  }
  BFS(n,m);
  return 0;
}
