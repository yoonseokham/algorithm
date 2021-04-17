#include <iostream>
#include <algorithm>
#define MAX 510
using namespace std;
int indx[4]={-1,0,1,0};
int jndx[4]={0,1,0,-1};


int brr[MAX][MAX]={0};
int arr[MAX][MAX]={0};

bool visit[MAX][MAX]={0};
int sum=arr[0][0];
int Ti[4][4]={{0,1,1,1},{0,0,0,1},{0,1,1,2},{0,1,1,2}};
int Tj[4][4]={{0,-1,0,1},{-1,0,1,0},{0,0,1,0},{0,-1,0,0}};
void T_deter(int ipos ,int jpos){
int sum=arr[ipos][jpos];
int a,b;
      for(int i=0;i<4;i++){
          sum=0;
        for(int j=0;j<4;j++){
          a=ipos+Ti[i][j];
          b=jpos+Tj[i][j];
          if(a>=0&&b>=0){
              sum+=arr[a][b];
          }
        }
        brr[ipos][jpos]=max(sum,brr[ipos][jpos]);
    }
}
void dfs(int ipos,int jpos,int cnt=1){
  int a,b;
    if(cnt==4){
        brr[ipos][jpos]=max(brr[ipos][jpos],sum);
      }
    else{
      for(int i=0;i<4;i++){
          a=ipos+indx[i];
          b=jpos+jndx[i];
          if(a>=0&&b>=0){
            if(visit[a][b]==false){
              sum+=arr[a][b];
              visit[a][b]=true;
              dfs(a,b,cnt+1);
              sum-=arr[a][b];
              visit[a][b]=false;
        }
      }
    }
  }
}
void tetromino(int rows,int cols){
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      visit[i][j]=1;
      sum=arr[i][j];
      dfs(i,j);
      visit[i][j]=0;
    }
  }
}
int main(void){
  int rows,cols;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>rows>>cols;
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      cin>>arr[i][j];
    }
  }
  tetromino(rows,cols);
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
    T_deter(i,j);
    }
  }
  int max=brr[0][0];
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if(max<brr[i][j])
        max=brr[i][j];
    }
  }
  cout<<max;
  return 0;
}
