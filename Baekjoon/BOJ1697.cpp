#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int visit[100001]={0};
queue <int> q;
bool segCheck(int k){
  if(k<0)  return false;
  if(k>100000) return false;
  return true;
}
void Jump(int k){
  while(!q.empty()){
    int index=q.front();
    q.pop();
    if(segCheck(index+1)&&visit[index+1]==0){
      visit[index+1]=visit[index]+1;
      q.push(index+1);}
    if(segCheck(index-1)&&visit[index-1]==0){
      visit[index-1]=visit[index]+1;
      q.push(index-1);}
    if(segCheck(index*2)&&visit[index*2]==0){
      visit[index*2]=visit[index]+1;
      q.push(index*2);
    }
  }
}
int main(void){
  int n,k;
  cin>>n>>k;
  visit[n]=1;
  q.push(n);
  Jump(k);
  cout<<visit[k]-1;
  return 0;
}
