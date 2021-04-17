#include <iostream>
#include <vector>
#include <queue>
#define MAX 501
using namespace std;
vector <int> v[MAX];
queue <int> q;
int link[MAX]={0};
int cost[MAX]={0};
int result[MAX]={0};
void topologicalSort(int n){
  if(q.empty())
    return ;
  else{
    int topIndx=q.front();
    q.pop();
    for(int i=0;i<v[topIndx].size();i++){
      int temp=v[topIndx].at(i);
      link[temp]--;
      result[temp]=result[temp]>result[topIndx]+cost[temp]?result[temp]:result[topIndx]+cost[temp];
      if(link[temp]==0){
        q.push(temp);
      }
    }
    topologicalSort(n);
  }
}
int main(void){
  int n,temp;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>cost[i];
    result[i]=cost[i];
    do{
      cin>>temp;
      if(temp!=-1)
      {
        v[temp].push_back(i);
        link[i]++;
      }
    }while(temp!=-1);
  }
  for(int i=1;i<=n;i++)
    if(link[i]==0)  q.push(i);
  topologicalSort(n);
  for(int i=1;i<=n;i++)
    cout<<result[i]<<"\n";
  return 0;
}
