#include <iostream>
#include <algorithm>
using namespace std;
#define SAFE 0//텅빈 공간
#define MAX 10// 배열의 크기를 10으로 둔 이유는 겉에 wall로 둘러싸려고
#define WALL 1
#define CORONA 2//바이러스이름
int surviorMAX=0;//생존자
int temp=0;
int arr[MAX][MAX]={0};//원래 입력받은 값
int brr[MAX][MAX]={0};
int indx[3]={0,0,0};//벽을 세울 3개의 위치 저장
int jndx[3]={0,0,0};
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
bool sameIndx(void){//벽 위치가 서로 중복이거나 safe아닌곳이라면 트루 리턴
  if(indx[0]==indx[1]&&jndx[0]==jndx[1])
    return true;
  if(indx[0]==indx[2]&&jndx[0]==jndx[2])
    return true;
  if(indx[1]==indx[2]&&jndx[1]==jndx[2])
    return true;
  if(indx[0]==indx[1]&&jndx[0]>jndx[1])
    return true;
  if(indx[1]==indx[2]&&jndx[1]>jndx[2])
    return true;
  if(arr[indx[0]][jndx[0]]!=SAFE||arr[indx[1]][jndx[1]]!=SAFE||arr[indx[2]][jndx[2]]!=SAFE)
    return true;
  else
    return false;
}
void wall_initer(int*indx,int*jndx,int n,int m){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
      brr[i][j]=arr[i][j];
  }
  for(int i=0;i<3;i++){
    brr[indx[i]][jndx[i]]=WALL;
  }
  return;
}
void corona_spread_ing(int n,int m,int in=0 ,int jn=0 ){
  if(in<=0||in>n||jn<=0||jn>m)
    return;
  if(brr[in][jn]==CORONA){
    for(int i=0;i<4;i++){
      if(brr[in+di[i]][jn+dj[i]]==SAFE){
        brr[in+di[i]][jn+dj[i]]=CORONA;
        corona_spread_ing(n,m,in+di[i],jn+dj[i]);
      }
    }
  }
}
int main(void)
{
  for(int i=0;i<MAX;i++){
    for(int j=0;j<MAX;j++)
      arr[i][j]=WALL,brr[i][j]=WALL;
  }
  int n,m,k=1;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
      cin>>arr[i][j];
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
      brr[i][j]=arr[i][j];
  }
  for(indx[0]=1;indx[0]<=n;indx[0]++){//3개의 벽정보 좌표 리턴
    for(jndx[0]=1;jndx[0]<=m;jndx[0]++){
      for(indx[1]=indx[0];indx[1]<=n;indx[1]++){
        for(jndx[1]=1;jndx[1]<=m;jndx[1]++){
          for(indx[2]=indx[1];indx[2]<=n;indx[2]++){
            for(jndx[2]=1;jndx[2]<=m;jndx[2]++){
                if(sameIndx())
                  continue;
                else{
                  temp=0;
                  wall_initer(indx,jndx,n,m);//벽을 세우고
                  for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++)
                    corona_spread_ing(n,m,i,j);//코로나 퍼트리고
                  }
                  for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                      if(brr[i][j]==SAFE)//생존자 카운트
                        ++temp;
                  }
                }
                surviorMAX=max(temp,surviorMAX);
            }
          }
        }
      }
    }
  }
}
 cout<<surviorMAX;
  return 0;
}
