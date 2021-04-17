#include <iostream>
#include <queue>
using namespace std;
int visit[1000001]={0};
queue <int> q;
bool SegCheck(int i,int f){
  if(1<=i&&i<=f) return true;
  return false;
}
int BFS(int f,int s,int g,int u,int d ){
  int temp;
  visit[s]=1;
  q.push(s);
  while(!q.empty()){
    temp=q.front();
    q.pop();
    int up=temp+u;
    int down=temp-d;
    if(SegCheck(up,f)&&visit[up]==0){
      q.push(up);
      visit[up]+=visit[temp]+1;
    }
    if(SegCheck(down,f)&&visit[down]==0){
      q.push(down);
      visit[down]+=visit[temp]+1;
    }
  }
  return visit[g]-1;
}
int main(void){
  int f,s,g,u,d,result;
  cin>>f>>s>>g>>u>>d;
  result=BFS(f,s,g,u,d);
  if(result==-1)
    cout<<"use the stairs";
  else
    cout<<result;
  return 0;
}
