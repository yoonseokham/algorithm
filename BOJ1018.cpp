#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 58
#define W 87
#define B 66
int arr[MAX][MAX]={0};
const int deter[2][8][8]=
{
{
{B,W,B,W,B,W,B,W},
{W,B,W,B,W,B,W,B},
{B,W,B,W,B,W,B,W},
{W,B,W,B,W,B,W,B},
{B,W,B,W,B,W,B,W},
{W,B,W,B,W,B,W,B},
{B,W,B,W,B,W,B,W},
{W,B,W,B,W,B,W,B}
},
{
{W,B,W,B,W,B,W,B},
{B,W,B,W,B,W,B,W},
{W,B,W,B,W,B,W,B},
{B,W,B,W,B,W,B,W},
{W,B,W,B,W,B,W,B},
{B,W,B,W,B,W,B,W},
{W,B,W,B,W,B,W,B},
{B,W,B,W,B,W,B,W}
}};
int diffrent_num_returner(int indx,int jndx,int n, int m){
int sum[2]={0};
if(indx+8>n||jndx+8>m)
  return 9999999;
  for(int k=0;k<2;k++){
    for(int i =indx;i<indx+8;i++){
      for(int j=jndx;j<jndx+8;j++){
        if(deter[k][i-indx][j-jndx]!=arr[i][j])
          sum[k]++;
        //cout<<arr[i][j]<<" ";
      }
      //cout<<"\n";
    }
  }
  return min(sum[0],sum[1]);// ? sum[0]:sum[1];
}
int main(void){
  int n,m,temp=0,result=9999999;
  cin>>n>>m;
  fgetc(stdin);//버퍼에 개행문자 버리기
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      arr[i][j]=fgetc(stdin);
    }
    fgetc(stdin);//버퍼에 개행문자 비우기
  }
  //cout<<diffrent_num_returner(0,5,n,m);
  for(int i=0;i<=n-8;i++){
    for(int j=0;j<=m-8;j++){
      temp=diffrent_num_returner(i,j,n,m);
      result=min(temp,result);// ? temp:result;
    }
  }
  cout<<result;
  // cout<<result<<"\n";
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<m;j++){
  //     cout<<arr[i][j]<<" ";//=fgetc(stdin);
  //   }
  //   cout<<"\n";//fgetc(stdin);
  // }
  return 0;
}
