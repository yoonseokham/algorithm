#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int arr[12][6]={0};

bool isSegFault(int i,int j){
  if(i<0||j<0||i>=12||j>=6) return true;
  return false;
}
void DFS(int index,int jndex,bool visit[][6],vector <pair<int,int> > & BreakBlock){
    for(int i=0;i<4;i++){
      int NewIndex=index+"0121"[i]-'1';
      int NewJndex=jndex+"1210"[i]-'1';
      if(arr[index][jndex]!='.'&&arr[index][jndex]==arr[NewIndex][NewJndex]&&!visit[NewIndex][NewJndex]&&!isSegFault(NewIndex,NewJndex)){
        visit[NewIndex][NewJndex]=true;
        BreakBlock.push_back(make_pair(NewIndex,NewJndex));
        DFS(NewIndex,NewJndex,visit,BreakBlock);
      }
    }
}
void DFS_All(void){
  bool visit[12][6]={0};
  for(int i=0;i<12;i++){
    for(int j=0;j<6;j++){
      if(arr[i][j]!='.'&&!visit[i][j]){
        vector <pair<int,int> > BreakBlock;
        BreakBlock.push_back(make_pair(i,j));
        visit[i][j]=true;
        DFS(i,j,visit,BreakBlock);
        if(BreakBlock.size()>=4){
          for(int k=0;k<BreakBlock.size();k++){
            arr[BreakBlock[k].first][BreakBlock[k].second]='.';
          }
        }
      }
    }
  }
}
void PushDown(void){

  for(int j=0;j<6;j++){
    queue <int> fallDown;
    for(int i=11;i>=0;i--){
      if(arr[i][j]!='.'){
        fallDown.push(arr[i][j]);
        arr[i][j]='.';
        }
      }
      for(int i=11;i>=0;i--){
        if(!fallDown.empty()){
        arr[i][j]=fallDown.front();
        fallDown.pop();
        }
      }
    }
  }

bool isSameArr(int brr[][6]){
  for(int i=0;i<12;i++){
    for(int j=0;j<6;j++){
      if(brr[i][j]!=arr[i][j])  return false;
    }
  }
  return true;
}
void copy(int brr[][6]){
  for(int i=0;i<12;i++){
    for(int j=0;j<6;j++){
      brr[i][j]=arr[i][j];
    }
  }
}
int main (void){
  int answer=0;
  for(int i=0;i<12;i++){
    for(int j=0;j<6;j++)
      arr[i][j]=fgetc(stdin);
    fgetc(stdin);
  }
  int brr[12][6]={0};
  copy(brr);
  do{
    DFS_All();
    PushDown();
    if(isSameArr(brr))  break;
    answer++;
    copy(brr);
  }while(1);
  cout<<answer;

  return  0;
}
