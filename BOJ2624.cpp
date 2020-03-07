#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1001
#define K 101
typedef struct _coin{
  int costOfcoin;
  int numOfCoin;
} Coin;
Coin wallet[K];
int dp[10001][K]={0};
void dp_initer(int cost,int k){
  dp[0][0]=1;
    for(int i=1;i<=k;i++){
        for(int n=0;n<=cost;n++){
          for(int j=0;j<=(wallet[i-1].costOfcoin)*(wallet[i-1].numOfCoin);j+=wallet[i-1].costOfcoin){
              if(dp[n][i-1]!=0&&j+n<=cost)//j+n<=cost이거 안붙이니까 런타임 오류남
                dp[j+n][i]+=dp[n][i-1];
              }
            }
          }
  return;
}
int main(void){
int cost,k;
cin>>cost>>k;
for(int i=0;i<k;i++){
  cin>>wallet[i].costOfcoin>>wallet[i].numOfCoin;
}
dp_initer(cost,k);
cout<<dp[cost][k];
  return 0;
}
