#include <iostream>
#include <string>
using namespace std;
int w,h;
int arr[50][50];
bool segCheck(int index,int jndex){
  if(index<0||index>=h||jndex<0||jndex>=w)
    return false;
  else
    return true;
}
void dfs(int index,int jndex,bool visit[][50]){
  int newIndex,newJndex;
  for(int i=0;i<8;i++){
    newIndex=index+"00122210"[i]-'1';
    newJndex=jndex+"12221000"[i]-'1';
    if(segCheck(newIndex,newJndex)&&visit[newIndex][newJndex]==false&&arr[newIndex][newJndex]==1){
      visit[newIndex][newJndex]=true;
      dfs(newIndex,newJndex,visit);
    }
  }
}
int dfsall(bool visit[][50]){
  int cnt=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(visit[i][j]==false&&arr[i][j]==1){
        cnt++;
        visit[i][j]=true;
        dfs(i,j,visit);
      }
    }
  }
  return cnt;
}
int main(void){
  while(true){
    bool visit[50][50]={false};
    cin>>w>>h;
    if(w==0&&h==0) break;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++)
        cin>>arr[i][j];
      }
    cout<<dfsall(visit)<<"\n";
  }

  return 0;
}
