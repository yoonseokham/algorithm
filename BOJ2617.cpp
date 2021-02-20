#include <iostream>
#include <vector>
using namespace std;
vector <int> grap[2][100];
int visit[100]={0};
int depth=0;
void dfs(int k,int num,bool visit []){
  for(int i=0;i<grap[k][num].size();i++){
    if(visit[grap[k][num][i]]==false){
      visit[grap[k][num][i]]=true;
      depth++;
      dfs(k,grap[k][num][i],visit);
    }
  }
}
int dfsall(int n){
  int cnt=0;
  for(int j=0;j<2;j++){
    for(int i=1;i<=n;i++){
      bool visit[100]={0};
      depth=1;
      visit[i]=true;
      dfs(j,i,visit);
      if(depth>(n+1)/2) cnt++;
    }
  }
  return cnt;
}
int main(void){
  int n,m,temp[2],mid=(n+1)/2;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>temp[0]>>temp[1];
    grap[0][temp[0]].push_back(temp[1]);
    grap[1][temp[1]].push_back(temp[0]);
  }
  cout<<dfsall(n);
}
