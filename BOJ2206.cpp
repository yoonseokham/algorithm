#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;
int arr[MAX][MAX]={0};
int counted=2000000;
bool visit[MAX][MAX][2]={0};
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};

typedef pair<int,int> Point;//첫번째 Pair는 좌표 두번쨰 pair는 지나온 걸이 &true false
queue <pair<Point,Point> >  q;

void BfsTravel(int n,int m){
  int nn;
  q.push({{0,0},{1,0}});
  visit[0][0][0]=true;
  while(!q.empty()){
  nn=q.size();
  for(int i=0;i<nn;i++){
    pair<Point,Point> temp=q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int temp_i=temp.first.first+di[i];
      int temp_j=temp.first.second+dj[i];
      int count=temp.second.first;
      int wallcrash=temp.second.second;
       if(temp_i>=0&&temp_i<n&&temp_j>=0&&temp_j<m){
         if (temp_i==n-1&&temp_j==m-1)
           counted=min(counted,count);
        if(wallcrash==0){
          if(arr[temp_i][temp_j]==1&&visit[temp_i][temp_j][0]==0){
            q.push({{temp_i,temp_j},{count+1,1}});
            visit[temp_i][temp_j][1]=true;
          }
          else if(arr[temp_i][temp_j]==0&&visit[temp_i][temp_j][0]==0){
            q.push({{temp_i,temp_j},{count+1,0}});
            visit[temp_i][temp_j][0]=true;
          }
        }
        else{
          if(arr[temp_i][temp_j]==0&&visit[temp_i][temp_j][1]==0){
            q.push({{temp_i,temp_j},{count+1,1}});
            visit[temp_i][temp_j][1]=true;
          }
        }
      }
    }
  }
}
}
int main(void){
  int n,m;
  cin>>n>>m;
  fgetc(stdin);
  for(int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      arr[i][j]=fgetc(stdin)-'0';
    }
    fgetc(stdin);
  }
  if(n==1&&m==1){
    cout<<"1";
    return 0;
  }
  BfsTravel(n,m);
  if(counted==2000000)
    cout<<"-1";
  else
    cout<<counted+1;
 return 0;
}
