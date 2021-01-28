#include <iostream>

using namespace std;
int dpIniter(int n){
  static int dp[1000001]={0};
  dp[1]=1;
  if(dp[n]!=0)  return dp[n];
  else{
    dp[n]=dpIniter(n-1)+1;
    if(n%2==0)  dp[n]=min(dp[n],dpIniter(n/2)+1);
    if(n%3==0)  dp[n]=min(dp[n],dpIniter(n/3)+1);
  }
  return dp[n];
}
int main(void){
  int x;
  cin>>x;
  cout<<dpIniter(x)-1;
  return 0;
}
