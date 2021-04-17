#include <iostream>
#define MAX 102
using namespace std;
int arr[MAX][MAX]={0};
int visit[MAX][MAX]={0};
int rows,cols;
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
void SolidCheaseRemover(void){
  for(int i=0;i<=rows+1;i++){
    for(int  j=0;j<=cols+1;j++){
      if(arr[i][j]==2&&visit[i][j]>=2)
        arr[i][j]=0;
      visit[i][j]=0;
    }
  }
}
int lastSolidChease(void){//-1이면 마지막아님 -1이 아니면 마지막인거고 남은 치즈갯수 리턴
  int counter=0;
  for(int i=1;i<=rows;i++){
    for(int j=1;j<=cols;j++){
      if(arr[i][j]==2)
        return -1;
      if(arr[i][j]==1)
        counter++;
    }
  }
  return counter;
}
void cheaseMelt(int cur_i=0,int cur_j=0){
  int temp_i;
  int temp_j;
  for(int i=0;i<4;i++){
    temp_i=di[i]+cur_i;
    temp_j=dj[i]+cur_j;
    if(!(temp_i<0||temp_j<0||temp_i>rows+1||temp_j>cols+1)){
        if(visit[temp_i][temp_j]==0&&arr[temp_i][temp_j]==0){
          visit[temp_i][temp_j]=1;
          cheaseMelt(temp_i,temp_j);
        }
        else if(arr[temp_i][temp_j]==2){
          visit[temp_i][temp_j]++;
        }
    }
  }


}
int main(void){
  cin>>rows>>cols;
  int temp,counter=0;
  for(int i=1;i<=rows;i++){ //1부터 rows까지 초기회
    for(int  j=1;j<=cols;j++){
      cin>>temp;
      if(temp==1)
        arr[i][j]=2;
      }
    }
    while(1){
    cheaseMelt();
    SolidCheaseRemover();
    counter++;
    temp=lastSolidChease();
    if(temp!=-1)
      break;
    }
cout<<counter;
  return 0;
}
