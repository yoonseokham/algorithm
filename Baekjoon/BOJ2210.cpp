#include <iostream>
#include <string>
#include <set>
using namespace std;

int arr[5][5]={0};
set <string> answer;
bool segCheck(int index,int jndex){
  if(index<0||jndex<0||index>=5||jndex>=5)  return false;
  return true;
}
void dfs(int index,int jndex,string s=""){
  int newIndex,newJndex;
  if(s.length()==6){
    answer.insert(s);
    return;
  }
  else{
    for(int i=0;i<4;i++){
      newIndex=index+"0121"[i]-'1';
      newJndex=jndex+"1210"[i]-'1';
      if(segCheck(newIndex,newJndex)){
        dfs(newIndex,newJndex,s+char(arr[newIndex][newJndex]));
      }
    }
  }
}
void dfsall(void){
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      dfs(i,j);
    }
  }
}
int main(void){
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++)
      cin>>arr[i][j];
  }
  dfsall();
  cout<<answer.size();
  return 0;
}
