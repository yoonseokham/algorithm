#include <iostream>
#include <algorithm>
#define MAX 2500001
using namespace std;
int Ti[MAX]={0};
int Pi[MAX]={0};
int dp[MAX]={0};
int max_p=0;
int n;
int go(int indx=1){
  if(indx>n+1)
    return -MAX;
  if(indx==n+1)
    return 0;
  if(dp[indx]!=-1)
    return dp[indx];
  else{
    int t1=go(indx+Ti[indx])+Pi[indx];
    int t2=go(indx+1);
    return dp[indx]=max(t1,t2);
  }
}
int main(void){
  cin>>n;
  Ti[0]=1;
  for(int i=1;i<=n;i++){
    cin>>Ti[i]>>Pi[i];
    dp[i]=-1;
  }
  cout<<go();
  //cout<<max_p;
  return 0;
}
