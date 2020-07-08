#include <iostream>
using namespace std;
int original[52][52]={0};
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
//i,j에 존재하는 미세먼지를 퍼지게 하는 함수
void spreader(int i,int j,int r,int c,int (*spread) [52]){
  int temp_i,temp_j,count=0,spreaded=original[i][j]/5;
    if(original[i][j]>=0){
      for(int k=0;k<4;k++){
        temp_i=i+di[k];
        temp_j=j+dj[k];
        if(!(temp_i<1||temp_j<1||temp_i>r||temp_j>c)&&(original[temp_i][temp_j]!=-1)){
              spread[temp_i][temp_j]+=spreaded;
              original[i][j]-=spreaded;
        }
      }
        spread[i][j]+=original[i][j];
    }
    if(original[i][j]==-1)
      spread[i][j]=-1;
}
//모든 인덱스에 대해 spreader를 호출해주는 함수
void AllSpreader(int r,int c){
int spread[52][52]={0};
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
        spreader(i,j,r,c,spread);
    }
  }
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      original[i][j]=spread[i][j];
    }
  }
}
//ina와 jna의 인덱스에 존재하는 원소를 ia,ja에 존재하는 원소로 바꿔주는 함수
//또 공기청정기의 최저 인덱스를 indx_i,indx_j로 받아서 일단 0으로 바꿔준다
void transfromAtoNewA(int ia,int ja,int ina,int jna,int indx_i,int indx_j){
  original[ina][jna]=original[ia][ja];
  int up_i=indx_i-1,down_i=indx_i;
  original[up_i][indx_j]=0;
  original[down_i][indx_j]=0;
}
int calculator(int r ,int c){
int sum=2;
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      sum+=original[i][j];
    }
  }
  return sum;
}
//공기청정기가 공기를 순환시켜주는 함수
void rotater(int indx_i,int indx_j,int r,int c){
  int up_i=indx_i-1,down_i=indx_i;
  original[up_i][indx_j]=0;
  original[down_i][indx_j]=0;
  for(int i=up_i;i>=2;i--)
    transfromAtoNewA(i-1,1,i,1,indx_i,indx_j);
  for(int i=1;i<c;i++)
    transfromAtoNewA(1,i+1,1,i,indx_i,indx_j);
  for(int i=1;i<up_i;i++)
    transfromAtoNewA(i+1,c,i,c,indx_i,indx_j);
  for(int i=c;i>=2;i--)
    transfromAtoNewA(up_i,i-1,up_i,i,indx_i,indx_j);
  for(int i=down_i;i<r;i++)
    transfromAtoNewA(i+1,1,i,1,indx_i,indx_j);
  for(int i=1;i<c;i++)
    transfromAtoNewA(r,i+1,r,i,indx_i,indx_j);
  for(int i=r;i>up_i+1;i--)
    transfromAtoNewA(i-1,c,i,c,indx_i,indx_j);
  for(int i=c;i>=2;i--)
    transfromAtoNewA(down_i,i-1,down_i,i,indx_i,indx_j);
  original[up_i][indx_j]=-1;
  original[down_i][indx_j]=-1;
}
int main(void){
  int r,c,t,indx_i,indx_j;
  cin>>r>>c>>t;
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      cin>>original[i][j];
      if(original[i][j]==-1){
        indx_i=i;
        indx_j=j;
      }
    }
  }
  for(int i=0;i<t;i++){
   AllSpreader(r,c);
    rotater(indx_i,indx_j,r,c);
  }
  cout<<calculator(r,c);
  return 0;
}
