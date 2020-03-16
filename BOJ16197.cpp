#include <iostream>
#include <stdio.h>
#include<algorithm>
#define MAX 22
char arr[MAX][MAX]={0};
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
using namespace std;
int count=-2;
int n,m;
int minx=11;
void moving_coin(int i1,int j1,int i2,int j2,int cnt=0){
int ni1,nj1,ni2,nj2;
if(cnt>10){
  return;
}
for(int i=0;i<4;i++){
    ni1=i1+di[i];
    nj1=j1+dj[i];
    ni2=i2+di[i];
    nj2=j2+dj[i];
    if((ni1==0||ni1==n+1||nj1==0||nj1==m+1)||(ni2==0||ni2==n+1||nj2==0||nj2==m+1)){
      if((ni1==0||ni1==n+1||nj1==0||nj1==m+1)&&(ni2==0||ni2==n+1||nj2==0||nj2==m+1))
        continue;
      else{
        minx=min(cnt+1,minx);
        continue;
      }
    }
    if(arr[ni1][nj1]=='#'||arr[ni2][nj2]=='#'){
      if(arr[ni1][nj1]=='#'&&arr[ni2][nj2]=='#')
        continue;
      else if(arr[ni1][nj1]=='#')
          moving_coin(i1,j1,ni2,nj2,cnt+1);
      else if(arr[ni2][nj2]=='#')
        moving_coin(ni1,nj1,i2,j2,cnt+1);
    }
    else
        moving_coin(ni1,nj1,ni2,nj2,cnt+1);
  }
}
int main(void) {
  bool only_once_if=false;
  cin>>n>>m;
  fgetc(stdin);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
      arr[i][j]=fgetc(stdin);
    fgetc(stdin);
  }
  int i1=0,j1=0,i2=0,j2=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(arr[i][j]=='o'){
        if(!only_once_if){
          i1=i;
          j1=j;
          only_once_if=true;
        }
        else{
          i2=i;
          j2=j;
        }
      }
  }
}
//cout<<i1<<j1<<i2<<j2;
moving_coin(i1 ,j1 ,i2 ,j2);
if(minx==11)
  cout<<-1;
else
  cout<<minx;
  return 0;
}
