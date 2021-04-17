#include <iostream>

using namespace std;
int main(void){
  int n;
  long long arr[101][101]={0};
  long long dp[101][101]={0};
  ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
  cin >>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>arr[i][j];
    }
  }
  dp[0][0]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<i;k++){
        if(arr[k][j]+k==i){
          dp[i][j]+=dp[k][j];
        }
      }
      for(int k=0;k<j;k++){
        if(arr[i][k]+k==j){
          dp[i][j]+=dp[i][k];
        }
      }
    }
  }
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<n;j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
cout<<dp[n-1][n-1];
  return 0;
}
