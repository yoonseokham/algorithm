#include <iostream>
#include <string>
#define HORIZEON 1
#define CROSS 2
#define VERTICAL 3

using namespace std;
int arr[17][17]={0};
int visit[17][17]={0};
int result=0;
bool SegCheck(int i,int j,int n){
  if(0<=i&&i<n&&0<=j&&j<n)
    return true;
  return false;
}
int pipDireaction(int TcurI,int TcurJ,int HcurI,int HcurJ){
  if(TcurI==HcurI)
    return HORIZEON;
  else if(TcurJ==HcurJ)
    return VERTICAL;
  else
    return CROSS;
}
void DFS(int n,int TcurI=0,int TcurJ=0,int HcurI=0,int HcurJ=1){
  int NewCurI,NewCurJ;
  if(HcurI==n-1&&HcurJ==n-1){
    result++;
  }
  else{
    int curState=pipDireaction(TcurI,TcurJ,HcurI,HcurJ);
    for(int i=0;i<3;i++){
      int NewTCurI=HcurI;
      int NewTCurJ=HcurJ;
      int NewHCurI="122"[i]-'1'+HcurI;
      int NewHCurJ="221"[i]-'1'+HcurJ;
      if(SegCheck(NewHCurI,NewHCurJ,n)) {
        if(curState==VERTICAL){
          if(i==0)  continue;

        }
        else if(curState==HORIZEON){
          if(i==2) continue;
        }
        if(i==1){
          if(arr[NewHCurI][NewHCurJ]!=1&&arr[NewHCurI-1][NewHCurJ]!=1&&arr[NewHCurI][NewHCurJ-1]!=1){
            DFS(n,NewTCurI,NewTCurJ,NewHCurI,NewHCurJ);
          }
        }
        else{
          if(arr[NewHCurI][NewHCurJ]!=1){
            DFS(n,NewTCurI,NewTCurJ,NewHCurI,NewHCurJ);
          }
        }
      }
    }
  }
}


int main(void){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>arr[i][j];
    }
  }
  DFS(n);
  cout<<result;
  return 0;
}
