#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 102
int arr[MAX][MAX]={0};
int copy_map[MAX][MAX]={0};
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
void normal_view(int n,int indx=1,int jndx=1){
  int new_i,new_j;
  if(copy_map[indx][jndx]==0){
    copy_map[indx][jndx]=1;
    for(int i=0;i<4;i++){
        copy_map[indx][jndx]=1;
        new_i=indx+di[i];
        new_j=jndx+dj[i];
        if(new_i>0&&new_i<101&&new_j>0&&new_j){
          if(arr[indx][jndx]==arr[new_i][new_j]){
            normal_view(n,new_i,new_j);
          }
        }
      }
    }
}
int watch(int n){
int sum=0;
for(int i=1;i<=n;i++){
  for(int j=1;j<=n;j++){
    if(copy_map[i][j]==0){
      normal_view(n,i,j);
      sum++;
    }
  }
}
 return sum;
}
int main(void){
int n;
cin>>n;
fgetc(stdin);
for(int i=1;i<=n;i++){
  for(int j=1;j<=n;j++){
    arr[i][j]=fgetc(stdin);
  }
  fgetc(stdin);
}
  cout<<watch(n)<<" ";
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      copy_map[i][j]=0;
      if(arr[i][j]=='R')
          arr[i][j]='G';
    }
  }
  cout<<watch(n);
  return 0;
}
