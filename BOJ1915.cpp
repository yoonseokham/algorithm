#include <iostream>
#include <algorithm>
using namespace std;
int arr[2001][2001]={0};
int dp[2001][2001]={0};
int Max=0;
int ThreeMin(int a,int b,int c){
  int temp=a>b?b:a;
  return temp>c?c:temp;
}

void dpIniter(int n){
  for(int k=1;k<=2*n;k++){
    for(int i=k;i>0;i--){
      if(arr[i][k+1-i]==1){
          dp[i][k+1-i]=ThreeMin(dp[i-1][k+1-i],dp[i-1][k-i],dp[i][k-i])+1;
          Max=max(Max,dp[i][k+1-i]);
        }
      }
    }
  }

int main(void){
  int n,m;
  cin>>n>>m;
  fgetc(stdin);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
      arr[i][j]=fgetc(stdin)-'0';
    fgetc(stdin);
  }
  dpIniter(n>m?n:m);
  cout<<Max*Max;
  return 0;
}
