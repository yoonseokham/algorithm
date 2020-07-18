#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;
vector <int> v[MAX];
int link[MAX]={0};
bool visit[MAX]={false};
priority_queue <int> q;
int PushAndPop(int n){
  return -1*n;
}
bool allVisit(int n){
  for(int i=1;i<=n;i++)
    if(!visit[i]) return false;
  return true;
}//전부 방문시 트루 리턴
void TopoloicalSort(int  n){
    if(q.empty()&&allVisit(n))
      return;
    else if(q.empty()&&!allVisit(n)){
      for(int i=1;i<=n;i++)
        if(!visit[i]&&link[i]==0) visit[i]=true,q.push(PushAndPop(i));
      TopoloicalSort(n);
    }
    else{
      int topIndx=PushAndPop(q.top());
      cout<<topIndx<<" ";
      q.pop();
      for(int i=0;i<v[topIndx].size();i++){
        if(!visit[v[topIndx][i]]){
            link[v[topIndx][i]]--;
            if(link[v[topIndx][i]]==0){
              q.push(PushAndPop(v[topIndx][i]));
              visit[v[topIndx][i]]=true;
            }
        }
      }
      TopoloicalSort(n);
    }
}
int main(void){
  int n,m,temp1,temp2;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>temp1>>temp2;
    v[temp1].push_back(temp2);
    link[temp2]++;
  }
  TopoloicalSort(n);
  return 0;
}
