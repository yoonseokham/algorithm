
#include <iostream>
using namespace std;
int sum=0;
int count=0;
int arr[50][50]={0};
int temp[50][50]={0};
bool move_map[50][50]={false};
bool visit[50][50]={false};
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
int abs(int a,int b){
  return a-b>0? a-b:b-a;
}
void local_move_initer(int n,int l,int r,int indx=0,int jndx=0){
int temp_i,temp_j;
  for(int i=0;i<4;i++){
    temp_i=indx+di[i];
    temp_j=jndx+dj[i];
    if(temp_i>=0&&temp_j>=0&&temp_i<n&&temp_j<n){
      if(move_map[temp_i][temp_j]==false&&l<=abs(arr[temp_i][temp_j],arr[indx][jndx])&&r>=abs(arr[temp_i][temp_j],arr[indx][jndx])){
        move_map[temp_i][temp_j]=true;
        visit[temp_i][temp_j]=true;
        sum+=arr[temp_i][temp_j];
        local_move_initer(n,l,r,temp_i,temp_j);
        count+=1;
      }
    }
  }
}

void every_popualtion_move(int n,int l,int r){
int num_of_move=0,part_population;
bool move=false;
  do{
    bool move=false;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){temp[i][j]=arr[i][j];}}
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          local_move_initer(n,l,r,i,j);
          if(move_map[i][j]&&count!=0){
            move=true;
            for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                  if(visit[i][j]){
                    temp[i][j]=sum/count;
                    // move_map[i][j]=false;
                    visit[i][j]=false;
                  // cout<<visit[i][j]<<" ";
                  }
                  // cout<<"\n";
              }

            }
            sum=0;
            count=0;
          }

    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){arr[i][j]=temp[i][j];}}
    if(!move)
      break;
    num_of_move++;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        move_map[i][j]=false;
      }}
  }while(true);
  cout<<num_of_move<<"\n";
}
int main(void){
  int n,l,r;
  cin>>n>>l>>r;
  for(int i=0;i<n;i++){
    for (int j=0;j<n;j++)
      cin>>arr[i][j];
  }
  every_popualtion_move(n,l,r);
  return 0;
}
