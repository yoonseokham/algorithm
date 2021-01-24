#include <iostream>
#include <queue>
#include <string>
#include <cstdio>
using namespace std;
int arr[30][30][30]={0};
int visit[30][30][30]={0};
int l,r,c;
typedef pair<int ,int> temp;
typedef pair<int,temp> Point;
bool SegCheck(Point cur){
  int cur_l=cur.first,cur_r=cur.second.first, cur_c=cur.second.second;
  if(0<=cur_l&&cur_l<l&&0<=cur_r&&cur_r<r&&0<=cur_c&&cur_c<c)
    return true;
  return false;
}
int BFS(Point start,Point end){
  int new_l,new_r,new_c;
  queue <Point> q;
  q.push(start);
  visit[start.first][start.second.first][start.second.second]=1;
  while(!q.empty()){
    Point temp=q.front();
    q.pop();
    for(int i=0;i<6;i++){
      new_l=temp.first+"111120"[i]-'1';
      new_r=temp.second.first+"012111"[i]-'1';
      new_c=temp.second.second+"121011"[i]-'1';
      Point NewCord={new_l,{new_r,new_c}};
      if(SegCheck(NewCord)){
        if(visit[NewCord.first][NewCord.second.first][NewCord.second.second]==0&&arr[NewCord.first][NewCord.second.first][NewCord.second.second]!='#'){
          visit[NewCord.first][NewCord.second.first][NewCord.second.second]=1+visit[temp.first][temp.second.first][temp.second.second];
          q.push(NewCord);}
      }
    }
  }
  return visit[end.first][end.second.first][end.second.second]-1;
}
int main(void){
  Point start;
  Point end;
  int result;
  while(true){
  cin>>l>>r>>c;
  if(l==0&&r==0&&c==0)  break;
  fgetc(stdin);
  for(int i=0;i<l;i++){
    for(int j=0;j<r;j++){
      for(int k=0;k<c;k++){
        visit[i][j][k]=0;
        arr[i][j][k]=fgetc(stdin);
        if(arr[i][j][k]=='S')
          start={i,{j,k}};
        else if(arr[i][j][k]=='E')
          end={i,{j,k}};
      }
      fgetc(stdin);
    }
    fgetc(stdin);
  }
  result=BFS(start,end);
  if(result==-1){
    cout<<"Trapped!\n";
  }
  else{
    cout<<"Escaped in "<<result<<" minute(s).\n";
  }
}
  return 0;
}
