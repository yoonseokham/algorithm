#include <bits/stdc++.h>
#define DEAD 1001
#define CLOCK 0
#define COUNTERCLOCK 1

using namespace std;
void rotater(vector<deque<int>>&round,int n,int m,int num,int direaction,int k){
int temp;
  for(int i=num-1;i<n;i++){
    if((i+1)%num==0){
      if(direaction==CLOCK){
        for(int j=0;j<k;j++){
          temp=round[i].back();
          round[i].pop_back();
          round[i].push_front(temp);
        }
      }
      else if(direaction==COUNTERCLOCK){
          for(int j=0;j<k;j++){
            temp=round[i].front();
            round[i].pop_front();
            round[i].push_back(temp);
          }
        }
      }
    }
}
bool segCheck(int n,int i){
  return (0<=i&&i<n);
}
bool SameEraser(int n,int m,int target,int i,int j,vector<deque<int>>&round){
int newI,newJ;
  for(int k=0;k<4;k++){
    newI=i+"0121"[k]-'1';
    newJ=(j+"1210"[k]-'1')%m;
    newJ= newJ==-1?m-1:newJ;
    if(segCheck(n,newI) && round[newI][newJ]==target){
      round[newI][newJ]=DEAD;
      round[i][j]=DEAD;
      SameEraser(n,m,target,newI,newJ,round);
    }
  }
  return round[i][j]==DEAD;
}
void adj_eraser(int n,int m,vector<deque<int>>&round){
int len=0;
double total=0.0;
bool erase=false;
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(round[i][j]!=DEAD) erase=max(erase,SameEraser(n,m,round[i][j],i,j,round));
  if(!erase){
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(round[i][j]!=DEAD){
          len++;
          total+=round[i][j];
        }
      }
    }
    if(len!=0){
      total=(double)(total/(double)len);
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(round[i][j]!=DEAD){
            if((double)round[i][j]>total) round[i][j]-=1;
            else if((double)round[i][j]<total) round[i][j]+=1;
          }
        }
      }
    }
  }
}
int main(void){
  int n,m,t,x,d,k,total=0;
  cin>>n>>m>>t;
  vector<deque<int>> round(n,(deque<int>(m,0)));
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>round[i][j];
  for(int i=0;i<t;i++){
    cin>>x>>d>>k;
    rotater(round,n,m,x,d,k);
    adj_eraser(n,m,round);
  }
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(round[i][j]!=DEAD) total+=round[i][j];
  cout<<total;
  return 0;
}
