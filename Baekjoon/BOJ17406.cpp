#include<bits/stdc++.h>
using namespace std;
int n,m,k,r,c,s,answer=100000000;

vector<tuple<int,int,int>> command;
vector<int> v;

void ArraySpiner(vector<vector<int>>& board,int r,int c,int s){
  pair<int,int> top={r-s-1,c-s-1},bottom={r+s-1,c+s-1};
  int curI,curJ;
  vector<vector<int>> temp=board;
  for(int k=0;k<s;k++){
    curI=top.first+k,curJ=top.second+k;
    if(curI==top.first+k){
      while(curJ<bottom.second-k){
          temp[curI][curJ+1]=board[curI][curJ];
          curJ++;
        }
      }
    if(curJ==bottom.second-k){
      while(curI<bottom.first-k){
          temp[curI+1][curJ]=board[curI][curJ];
          curI++;
        }
      }
      if(curI==bottom.first-k){
        while(curJ>top.second+k){
            temp[curI][curJ-1]=board[curI][curJ];
            curJ--;
          }
        }
        if(curJ==top.second+k){
          while(curI>top.first+k){
              temp[curI-1][curJ]=board[curI][curJ];
              curI--;
            }
          }
  }
  board=temp;
}
void BackTracking(vector<vector<int>>& real_board,vector<vector<int>>& board){
  static bool visit[50]={0};
  int sum=0;
  if(v.size()==k){
    board=real_board;
    for(int i=0;i<k;i++) ArraySpiner(board,get<0>(command[v[i]]),get<1>(command[v[i]]),get<2>(command[v[i]]));
    for(int i=0;i<n;i++){
      sum=0;
      for(int j=0;j<m;j++) sum+=board[i][j];
      answer=min(sum,answer);
    }
    return;
  }
  else{
    for(int i=0;i<k;i++){
      if(!visit[i]){
        visit[i]=true;
        v.push_back(i);
        BackTracking(real_board,board);
        visit[i]=false;
        v.pop_back();
      }
    }
  }
}
int main(void){

  cin>>n>>m>>k;
  vector<vector<int>> board(n,vector<int>(m,0));
  vector<vector<int>> real_board(n,vector<int>(m,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>board[i][j];
      real_board[i][j]=board[i][j];
    }
  }
  for(int i=0;i<k;i++){
    cin>>r>>c>>s;
    command.push_back({r,c,s});
  }
BackTracking(real_board,board);
cout<<answer;
  return 0;
}
