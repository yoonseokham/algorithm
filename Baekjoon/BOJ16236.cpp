#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int arr[21][21]={0};
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
int global_counter=0;
typedef pair<int,int> a;
typedef pair< a, a > shark_info;
shark_info shark;
bool edible_fish(int n){
  for(int i=0;i<n;i++ ){
    for(int j=0;j<n;j++){
      if(arr[i][j]!=0&&arr[i][j]<shark.second.first)
        return true;
    }
  }
  return false;
}
int pass_through(int n,int i,int j){
  if(i<0||j<0||i>=n||j>=n)
    return 0;
  else if(arr[i][j]==0||arr[i][j]==shark.second.first)
    return 1;
  else if(arr[i][j]<shark.second.first)
    return 2;
  return 0;
}
int BFS(int n){
  int visit[21][21]={0};
  visit[shark.first.first][shark.first.second]=1;
  queue < pair <int ,int> > shark_walk;
  int local_counter=0,size_shark_walk=1;
  bool fish_find=false;

  if(!edible_fish(n))
    return 0;
  else{
    shark_walk.push(shark.first);

    while(!shark_walk.empty()&!fish_find){
      local_counter++;
      size_shark_walk=shark_walk.size();
      for(int j=0;j<size_shark_walk;j++){
        pair<int,int> temp=shark_walk.front();
        shark_walk.pop();
        for(int i=0;i<4;i++){
          int temp_i=temp.first+di[i];
          int temp_j=temp.second+dj[i];
          if(pass_through(n,temp_i,temp_j)==1){
              if(visit[temp_i][temp_j]==0){
              visit[temp_i][temp_j]=1;
              shark_walk.push({temp_i,temp_j});
            }
          }
          else if(pass_through(n,temp_i,temp_j)==2){
            if(visit[temp_i][temp_j]==0){
            fish_find=true;
            visit[temp_i][temp_j]=2;}
        }
      }
    }

  }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(visit[i][j]==2)
        {
          shark.first.first=i;
          shark.first.second=j;
          arr[i][j]=0;
          shark.second.second+=1;
          if(shark.second.second==shark.second.first){
            shark.second.first+=1;
            shark.second.second=0;
          }
          return local_counter;
        }
      }
    }
}
return 0;
}

void shark_progress(int n){
  int temp=BFS(n);
  if(temp==0)
    return;
  else{
    global_counter+=temp;
    shark_progress(n);
  }
}
int main(void){
  int n,m;
  shark.second.first=2;
  shark.second.second=0;
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>arr[i][j];
      if(arr[i][j]==9){
        shark.first.first=i,shark.first.second=j;
        arr[i][j]=0;}
    }
  }
  shark_progress(n);
  cout<<global_counter;
  return 0;
}
