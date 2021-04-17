#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int arr[500][500]={0};
int dp[500][500]={0};
bool visit[500][500]={false};
bool SegfaultCheck(int index,int jndex,int n,int m){
  if(index<0||jndex<0||index>=n||jndex>=m){
    return true;
  }
  return false;
}
int DFS(int index,int jndex,int n,int m){
int NewIndex=index,NewJndex=jndex;
  if(SegfaultCheck(index,jndex,n,m))
    return 0;
  else if(visit[index][jndex])
    return dp[index][jndex];
  else{
    visit[index][jndex]=true;
    for(int i=0;i<4;i++){
      NewIndex=index+"0121"[i]-'0'-1;
      NewJndex=jndex+"1210"[i]-'0'-1;
      if(arr[index][jndex]>arr[NewIndex][NewJndex])
        dp[index][jndex]+=DFS(NewIndex,NewJndex,n,m);
    }
  }
  return dp[index][jndex];
}

int main(void){
  int n,m;
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin>>n>>m;
  dp[n-1][m-1]=1;
  visit[n-1][m-1]=true;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      cin>>arr[i][j];
  }
  cout<<DFS(0,0,n,m);
  return 0;
}
