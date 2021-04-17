#include <iostream>
using namespace std;

int dpIniter(int n){
  int dp[31]={0};
  int adp[31]={0};
  dp[0]=1;
  dp[1]=1;
  adp[1]=1;
  adp[2]=3;
  adp[3]=1;
  adp[4]=5;
  for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+2*dp[i-2];
    if(i>=5)
      adp[i]=adp[i-2]+2*adp[i-4];
  }
    return (dp[n]+adp[n])/2;

}
int main(void){
  int n;
  cin>>n;
  cout<<dpIniter(n);
  return 0;
}
