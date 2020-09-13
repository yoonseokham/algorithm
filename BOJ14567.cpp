#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;

vector<int> v[MAX];
queue <int> q;
int indegree[MAX]={0};
bool visit[MAX]={false};
int semester[MAX]={0};
void zeroPush(int n){
  for(int i=1;i<=n;i++){
    if(indegree[i]==0 && !visit[i] ){
      q.push(i);
      visit[i]=true;
      // semester[i]=1;
    }
  }
}
void topologySort(int n){
  int top,temp,count=0;
  zeroPush(n);
  while(!q.empty()){
    count++;
    while(!q.empty()){
      top=q.front();
      q.pop();
      for(int i=0;i<v[top].size();i++){
        temp=v[top][i];
        indegree[temp]--;
        if(indegree[temp]==0){
          semester[temp]=count;
        }
      }
    }
  zeroPush(n);
  }
  for(int i=1;i<=n;i++)
    cout<<semester[i]+1<<" ";
}
int main(void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n,m,temp[2];
  cin>>n>>m;
  for (int i=0;i<m;i++){
    cin>>temp[0]>>temp[1];
    v[temp[0]].push_back(temp[1]);
    indegree[temp[1]]++;
  }
  topologySort(n);
  return 0;
}
