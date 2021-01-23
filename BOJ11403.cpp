#include <iostream>
using namespace std;
bool visit[101][101]={false};
int arr[101][101]={0};
void DFS(int n,int start,int cur){
  for(int i=1;i<=n;i++){
    if(arr[cur][i]==1&&!visit[start][i]){
      visit[start][i]=true;
      DFS(n,start,i);
    }
  }
}
int main(void){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      cin>>arr[i][j];
  }
  for(int i=1;i<=n;i++)
    DFS(n,i,i);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      cout<<visit[i][j]<<" ";
    cout<<"\n";
  }
}
