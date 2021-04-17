#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 16
long long arr[MAX][MAX]={0};
long long dp[MAX][MAX]={0};
void dp_initer(long long n,long long m,long long indx,long long jndx){
  for(long long i=1;i<=indx;i++){
    for(long long j=1;j<=jndx;j++){
      dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
  }
  for(long long i=indx;i<n;i++){
    for(long long j=jndx;j<m;j++){
      dp[i][j]=dp[indx][jndx];
    }
  }
  for(long long i=indx+1;i<n;i++){
    for(long long j=jndx+1;j<m;j++){
      dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
  }
  for(long long i=0;i<n;i++){
    for(long long j=0;j<m;j++){
      cout<<dp[i][j]<<" ";//=dp[i-1][j]+dp[i][j-1];
    }
    cout<<"\n";
  }
}
int main(void){
  long long n,m,circle,sum=0,indx,jndx;
  cin>>n>>m>>circle;
  for(long long i=0;i<n;i++){
    for(long long j=0;j<m;j++){
      arr[i][j]=++sum;
      dp[i][j]=1;
      if(sum==circle){//동그라미친 원소의 위치 저장
        indx=i;
        jndx=j;
      }
    }
  }
  if(circle==0){
      indx=n-1;
      jndx=m-1;
  }
  dp_initer(n,m,indx,jndx);
  cout<<dp[n-1][m-1];
  return 0;
}
