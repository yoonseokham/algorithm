#include<bits/stdc++.h>
#define MAX 10000000
using namespace std;

bool segCheck(int i,int j,int n){
  return (i>=0 &&j>=0 && i<n&&j<n);
}
int bfs(int n,int arr[50][50]){
  int dp[50][50]={0};
  int NewI,NewJ;
  tuple<int,int,int> temp;
  priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;//부신벽의 갯수,i,j

  for(int i=0;i<n;i++) fill(dp[i],dp[i]+n,MAX);
  dp[0][0]=0;
  pq.push({0,0,0});
  
  while(dp[n-1][n-1]==MAX){
    temp=pq.top();
    pq.pop();
    for(int i=0;i<4;i++){
      NewI=get<1>(temp)+"0121"[i]-'1';
      NewJ=get<2>(temp)+"1210"[i]-'1';
      if(segCheck(NewI,NewJ,n)){
        if(arr[NewI][NewJ]==1&&dp[NewI][NewJ]>get<0>(temp)){
          dp[NewI][NewJ]=get<0>(temp);
          pq.push({dp[NewI][NewJ],NewI,NewJ});
        }
        else if(arr[NewI][NewJ]==0&&dp[NewI][NewJ]>get<0>(temp)+1){
          dp[NewI][NewJ]=get<0>(temp)+1;
          pq.push({dp[NewI][NewJ],NewI,NewJ});
        }
      }
    }
  }
  return dp[n-1][n-1];
}
int main(void){
  int n,arr[50][50]={0};
  cin >>n;
  fgetc(stdin);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      arr[i][j]=fgetc(stdin)-'0';
    fgetc(stdin);
  }
  cout<<bfs(n,arr);
  return 0;
}
