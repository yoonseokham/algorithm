#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001]={0};
int brr[100001]={0};
int dpIniter(int n,int* array){
  int dp[100001][10]={0};
  int Max=1;
  dp[1][array[1]]=1;
  for(int i=2;i<=n;i++){
    for(int j=0;j<=array[i];j++){
      dp[i][array[i]]=max(dp[i][array[i]],dp[i-1][j]);
    }
    dp[i][array[i]]+=1;
    Max=max(Max,dp[i][array[i]]);
  }
  return Max;
}
int main(void){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
    brr[n-i+1]=arr[i];
  }
  cout<<max(dpIniter(n,brr),dpIniter(n,arr));
  return 0;
}
