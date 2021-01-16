#include <iostream>
#include <algorithm>
using namespace std;
int arr[301]={0};
int dp[301][2]={0};
void dpIniter(int n){
  dp[1][0]=arr[1];
  dp[2][0]=arr[2];
  dp[2][1]=arr[1]+arr[2];
  for(int i=3;i<=n;i++){
    dp[i][0]=max(dp[i-2][0],dp[i-2][1])+arr[i];
    if(dp[i-1][0]!=0)
      dp[i][1]=dp[i-1][0]+arr[i];
  }
}
int main(void){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  dpIniter(n);
  cout<<max(dp[n][0],dp[n][1]);
  return 0;
}
