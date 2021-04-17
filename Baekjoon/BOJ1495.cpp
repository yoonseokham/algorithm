#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
int dp[102][1001]={0};
int n ,start,Max;
void dpIniter(int n){
  int result=-1;
  dp[0][v[0]]=1;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=Max;j++){
      if(dp[i-1][j]!=-1){
        if(j+v[i]<=Max){
          dp[i][j+v[i]]=1;
        }
        if(j-v[i]>=0){
          dp[i][j-v[i]]=1;
        }
      }
    }
  }
  for(int j=0;j<=Max;j++){
    if(dp[n][j]!=-1)
      result=j;
  }
  cout<<result;
}
int main(void){
  cin>>n>>start>>Max;
  int temp;
  v.push_back(start);
  for(int i=0;i<n;i++){
    cin>>temp;
    v.push_back(temp);
  }
  for(int i=0;i<102;i++){
    for(int j=0;j<1001;j++)
      dp[i][j]=-1;
  }
  dpIniter(n);
  return 0;
}
