#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101
int arr[MAX][MAX]={0};
int visited[MAX][MAX]={0};
void visiting(int startIindx,int startJindx,int rain){
  visited[startIindx][startJindx]=true;
  int di[4]={-1,0,1,0};
  int dj[4]={0,1,0,-1};
  int newIindx,newJindx;
  for(int i=0;i<4;i++){
    newIindx=startIindx+di[i];
    newJindx=startJindx+dj[i];
    if(newIindx>=0&&newIindx<MAX&&newJindx>=0&&newJindx<MAX){
        if(!visited[newIindx][newJindx]&&arr[newIindx][newJindx]>rain){
          visiting(newIindx,newJindx,rain);
        }
    }
  }
}
int connected_component(int n){
int real_sum=0;
  for(int k=0;k<=100;k++){
    int sum=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(arr[i][j]>k&&!visited[i][j]){
          visiting(i,j,k);
          sum++;
        }
      }
    }
    real_sum=max(real_sum,sum);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        visited[i][j]=false;
      }
    }
  }
  return real_sum;
}
int main(void)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
          cin>>arr[i][j];
    }
cout<<connected_component(n);
    return 0;
}
