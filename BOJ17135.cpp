#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 20
using namespace std;
vector <int> comdination;
bool visit[MAX]={0};
int temp2[MAX][MAX]={0};
int temp[MAX][MAX]={0};
int initial_map[MAX][MAX]={0};
int di[3]={0,-1,0};
int dj[3]={-1,0,1};
int local_counter=0;
int global_counter=0;
void temp2_initer(int n,int m){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      temp2[i][j]=initial_map[i][j];
  }
}
void slideDown(int n,int m){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
    {
      if(i==0)
        temp[i][j]=0;
      else{
        temp[i][j]=temp2[i-1][j];
        if(temp[i][j]==2)
          temp[i][j]=0;
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      temp2[i][j]=temp[i][j];
  }
}
void target(int n,int m,int d,int archer_jndx){
  queue <pair <int,int> > q;
  if(temp2[n-1][archer_jndx]==1){
    local_counter++;
    temp2[n-1][archer_jndx]=2;
    return;
  }
  else if(temp2[n-1][archer_jndx]==2)
    return;
  q.push({n-1,archer_jndx});
  int sizeOfQueue=1,temp_i,temp_j;
  while(--d){
    sizeOfQueue=q.size();
  for(int i=0;i<sizeOfQueue;i++){
    for(int j=0;j<3;j++){
      temp_i=q.front().first+di[j];
      temp_j=q.front().second+dj[j];
      if(temp_i<0||temp_j<0||temp_i>=n||temp_j>=m)
        continue;
      else{
        if(temp2[temp_i][temp_j]==1){
          local_counter++;
          temp2[temp_i][temp_j]=2;
          return;
        }
        else if(temp2[temp_i][temp_j]==2){
          return;}
        else{
            q.push({temp_i,temp_j});
        }
      }
    }
    q.pop();
  }
}
}

void BackTrack(int n,int m,int d,int indx=0,int cnt=0){
  if(cnt==3){
    local_counter=0;
    temp2_initer(n,m);
    for(int i=0;i<n;i++){
      for(int i=0;i<comdination.size();i++){
        target(n,m,d,comdination[i]);
      }
      slideDown(n,m);
    }
    global_counter=max(global_counter,local_counter);
  }
  else{
    for(int i=indx;i<m;i++){
      if(visit[i]==false){
        visit[i]=true;
        comdination.push_back(i);
          BackTrack(n,m,d,i+1,cnt+1);
        visit[i]=false;
        comdination.pop_back();
      }
    }
  }
}
int main(void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n,m,d;
  cin>>n>>m>>d;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>initial_map[i][j];
    }
  }
  BackTrack(n,m,d);
  cout<<global_counter;
  return 0;
}
