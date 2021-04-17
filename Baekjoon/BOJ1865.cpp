#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool BellmanFord(int n,int m,vector <pair<int,int>> v[]){
  int NodeCost[501]={0};
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      for(int k=0;k<v[j].size();k++){
        if(NodeCost[v[j][k].first]>v[j][k].second+NodeCost[j]){
          NodeCost[v[j][k].first]=v[j][k].second+NodeCost[j];
          if (i==n) return false;
        }
      }
    }
  }
  return true;
}
int main(void){
int testcase,n,m,w,start,end,weight;
ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin>>testcase;
  for(int i=0;i<testcase;i++){
    vector <pair<int,int>> v[501];
    cin>>n>>m>>w;
    for(int j=0;j<m;j++){
      cin>>start>>end>>weight;
      v[start].push_back({end,weight});
      v[end].push_back({start,weight});
    }
    for(int j=0;j<w;j++){
      cin>>start>>end>>weight;
      v[start].push_back({end,-1*weight});
    }
    BellmanFord(n,m,v)?puts("NO"):puts("YES");
  }
  return 0;
}
