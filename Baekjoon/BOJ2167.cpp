#include <iostream>
#define MAX 302
using namespace std;
int arr[MAX][MAX]={0};
int dp[MAX][MAX]={0};
void sum_of_arr(int rows,int cols,int* a){
   cout<<dp[a[2]][a[3]]-dp[a[0]-1][a[3]]-dp[a[2]][a[1]-1]+dp[a[0]-1][a[1]-1]<<" ";
}
int main(void){
  int rows,cols,n;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>rows>>cols;
  for(int i=1;i<=rows;i++){
    for(int j=1;j<=cols;j++){
      cin>>arr[i][j];
    }
  }
  for(int i=1;i<=rows;i++){
    for(int j=1;j<=cols;j++){
      dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
    }
}
  cin>>n;
  for(int i=0;i<n;i++){
    int a[4];
    for(int j=0;j<4;j++){
      cin>>a[j];
    }
    sum_of_arr(rows,cols,a);
  }
  return 0;
}
