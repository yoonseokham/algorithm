#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;
vector <int> v[MAX];
int link[MAX]={0};
priority_queue <int> q;
int PushAndPop(int n){
  return -1*n;
}
void TopoloicalSort(int  n){
    if(q.empty()) return;
    else{
      int topIndx=PushAndPop(q.top());
      cout<<topIndx<<" ";
      q.pop();
      for(int i=0;i<v[topIndx].size();i++){
            link[v[topIndx][i]]--;
            if(link[v[topIndx][i]]==0){
              q.push(PushAndPop(v[topIndx][i]));
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
  for(int i=1;i<=n;i++)
    if(link[i]==0) q.push(PushAndPop(i));
  TopoloicalSort(n);
  return 0;
}
