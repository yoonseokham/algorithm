#include <iostream>
#include <vector>
#include <string>
using namespace std;

int arr[500][500]={0};
int dp[500][500]={0};
bool visit[500][500]={0};
int Answer=0;

int max(int a,int b){
  return a>b?a:b;
}
bool SegfaultCheck(int index,int jndex,int n){
  if(index<0||jndex<0||index>=n||jndex>=n) return true;
  return false;
}
int dpIniter(int index,int jndex,int n){//i,j에 방생했을때 최대 사는 날짜
  int NewIndex,NewJndex;
  bool jumpAble=false;
  if(SegfaultCheck(index,jndex,n))  return 0;
  if(visit[index][jndex]) return dp[index][jndex];

  else{
    visit[index][jndex]=true;
    for(int i=0;i<4;i++){
      NewIndex=index+"0121"[i]-'1';
      NewJndex=jndex+"1210"[i]-'1';
      if(arr[index][jndex] < arr[NewIndex][NewJndex]){
        jumpAble=true;
        dp[index][jndex]=max(dp[index][jndex],dpIniter(NewIndex,NewJndex,n)+1);
        Answer=max(Answer,dp[index][jndex]);
      }
    }
  if(jumpAble)
    return dp[index][jndex];
  else
    return dp[index][jndex]=1;
  }
}
void FreePanda(int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(!visit[i][j])
        dpIniter(i,j,n);
    }
  }
}
int main(void){
  int n;
  cin>>n;
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cin>>arr[i][j];
  }
  FreePanda(n);
  cout<<Answer;
}
