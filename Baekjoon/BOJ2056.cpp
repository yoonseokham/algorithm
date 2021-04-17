#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;
vector <int> v[MAX];
queue <int> q;
int link[MAX]={0};
int cost[MAX]={0};
int result[MAX]={0};
void topologicalSort(int n){
  int topIdx,tmp;

    for(int i=1;i<=n;i++){
      if(link[i]==0)  q.push(i);
    }

  while(!q.empty()){
    topIdx=q.front();
    q.pop();
    for(int i=0;i<v[topIdx].size();i++){
    tmp=v[topIdx].at(i);//v[topIdx][i]
    result[tmp]=result[tmp]>result[topIdx]+cost[tmp]?result[tmp]:result[topIdx]+cost[tmp];
    if(--link[tmp]==0)   q.push(tmp);
    }
  }
  return ;
}
int main(void){
  int n,preWork,tmp,max=0;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>cost[i];
    result[i]=cost[i];
    cin>>preWork;
    for(int j=0;j<preWork;j++){
      cin>>tmp;
      v[tmp].push_back(i);
      link[i]++;
    }
  }
  topologicalSort(n);
  for(int i=1;i<=n;i++)
    max=result[i]>max?result[i]:max;
  cout<<max;
  return 0;
}
