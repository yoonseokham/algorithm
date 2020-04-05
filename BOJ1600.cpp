#include <iostream>
#include <queue>
#include <vector>
#define MAX 210
int jumpCount=0;
using namespace std;
int arr[MAX][MAX]={0};
bool visited[MAX][MAX][33]={0};
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
int jump_i[8]={-2,-1,1,2,2,1,-1,-2};
int jump_j[8]={1,2,2,1,-1,-2,-2,-1};
typedef struct _point{
  int i_pos;
  int j_pos;
  int move;
}Point;
queue <Point> q;
void BFS(int w,int h,int moveMax){
  int indx=0,jndx=0,Move=0,nindx,njndx,nMove;
  Point a;
  a.i_pos=indx;
  a.j_pos=jndx;
  a.move=Move;
  q.push(a);
  while(!q.empty()){
    int n=q.size();
    for(int k=0;k<n;k++){
      indx=q.front().i_pos;
      jndx=q.front().j_pos;
      Move=q.front().move;
      if(indx==w-1&&jndx==h-1){
        cout <<jumpCount;
        return;
      }
      for(int i=0;i<4;i++){
         nindx=indx+di[i];
         njndx=jndx+dj[i];
         nMove=Move;
        if(nindx>=0&&njndx>=0&&nindx<w&&njndx<h){
          if(arr[nindx][njndx]==0&&visited[nindx][njndx][nMove]==0){
              Point a;
              a.i_pos=nindx;
              a.j_pos=njndx;
              a.move=nMove;
              q.push(a);
              visited[nindx][njndx][nMove]=true;
            }
          }
        }
        if(moveMax>Move){
        for(int i=0;i<8;i++){
           nindx=indx+jump_i[i];
           njndx=jndx+jump_j[i];
           nMove=Move;
          if(nindx>=0&&njndx>=0&&nindx<w&&njndx<h){
            if(arr[nindx][njndx]==0&&visited[nindx][njndx][nMove+1]==0){
                Point a;
                a.i_pos=nindx;
                a.j_pos=njndx;
                a.move=nMove+1;
                q.push(a);
                visited[nindx][njndx][nMove+1]=true;

              }
            }
          }
        }
      q.pop();
    }
    jumpCount++;
  }
  cout<<-1;
}
int main(void){
  int w,h,move;
  cin>>move>>h>>w;
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++)
      cin>>arr[i][j];
  }
  BFS( w, h,move);
  return 0;
}
