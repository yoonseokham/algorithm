#include <iostream>
using namespace std;
int max(int a,int b,int c){
  int temp=a>b?a:b;
  return temp>c?temp:c;
}
int main(void){
  ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
  int n,m;
  cin>>n>>m;
  int arr[1001][1001]={0};
  int dp[1001][1001]={0};
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>arr[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      dp[i][j]+=arr[i][j]+max(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
    }
  }
  cout<<dp[n][m];
  return 0;
}
