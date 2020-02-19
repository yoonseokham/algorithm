#include <iostream>
#include <algorithm>
#define MAX_N 101
#define MAX_K 100001
using namespace std;
int dp[MAX_K][MAX_N]={0};
int arr[MAX_N][2]={0};//무게 가치
void nomal_bag(int n,int k){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      if(j>=arr[i][0])
          dp[j][i]=max(dp[j][i-1],dp[ j-arr[i][0] ][i-1]+arr[i][1]);
      else
          dp[j][i]=dp[j][i-1];
    }
  }
  sort(dp[k],dp[k]+MAX_N);
  cout<<dp[k][MAX_N-1];
}
int main(void){
  int n,k,temp;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>arr[i][0]>>arr[i][1];
    //=max(temp,arr[i][1]);
  }
  nomal_bag(n,k);
  return 0;
}
