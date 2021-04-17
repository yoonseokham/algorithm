//BOJ N과M (2) 15650번
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define MAX 53
using namespace std;
void CandyCounter(int (*arr) [MAX], int i,int j ,int indx ,int jndx,int size );

priority_queue< int, vector<int>, less<int> > pq;
void swap(int (*arr) [MAX], int i,int j ,int indx ,int jndx ){//i,j원소를 indx jndx와 교체
  int temp_i_j=arr[i][j];
  arr[i][j]=arr[indx][jndx];
  arr[indx][jndx]=temp_i_j;
}
void CandyGame(int (*arr) [MAX],int size){
int MaxCandy=0;
int temp=0;
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
  for(int i=1;i<=size;i++){
    for(int j=1;j<=size;j++){
      for(int k=0;k<4;k++){
        swap(arr,i,j,i+di[k],j+dj[k]);
        CandyCounter(arr,i,j,i+di[k],j+dj[k],size);
        swap(arr,i,j,i+di[k],j+dj[k]);
        if(pq.top()==size-1)
          return;
      }
    }
  }
}
void CandyCounter(int (*arr) [MAX], int i,int j ,int indx ,int jndx,int size ){
  int sum[4]={0,0,0,0};
  for(int i=1;i<=size;i++){
    for(int j=1;j<=size;j++){
      if(arr[i][j]==0)
        return;
    }
  }
  for(int k=1;k<size;k++){
    if(arr[i][k]==arr[i][k+1]&&arr[i][k]>0&&arr[i][k+1]>0){
        sum[0]++;
        pq.push(sum[0]);
        if(sum[0]==size-1)
          return;
    }
    else if((arr[i][k]!=arr[i][k+1]&&arr[i][k]>0&&arr[i][k+1]>0)){
      if(sum[0]==size-1)
        return;
      pq.push(sum[0]);
      sum[0]=0;

    }

    if(arr[indx][k]==arr[indx][k+1]&&arr[indx][k]>0&&arr[indx][k+1]>0){
      sum[1]++;
      pq.push(sum[1]);
      if(sum[1]==size-1)
        return;
    }
    else if(arr[indx][k]!=arr[indx][k+1]&&arr[indx][k]>0&&arr[indx][k+1]>0){
      if(sum[1]==size-1)
        return;
        pq.push(sum[1]);
        sum[1]=0;

      }
    if(arr[k+1][j]==arr[k][j]&&arr[k+1][j]>0&&arr[k][j]>0){
        sum[2]++;
        pq.push(sum[2]);
        if(sum[2]==size-1)
          return;
    }
    else if(arr[k+1][j]!=arr[k][j]&&arr[k+1][j]>0&&arr[k][j]>0){
      if(sum[2]==size-1)
        return;
        pq.push(sum[2]);
        sum[2]=0;
      }
    if(arr[k+1][jndx]==arr[k][jndx]&&arr[k+1][jndx]>0&&arr[k][jndx]>0){
      sum[3]++;
      pq.push(sum[3]);
      if(sum[3]==size-1)
        return;
    }
    else if(arr[k][jndx]!=arr[k+1][jndx]&&arr[k][jndx]>0&&arr[k+1][jndx]>0){
      if(sum[3]==size-1)
        return;
        pq.push(sum[3]);
        sum[3]=0;

      }

}
  return;// sum[3]+1;
}
int  main(void){
  pq.push(1);//우선순위 큐가 비는걸 방지
  int arr[MAX][MAX]={0};
  int size;
  cin>>size;
  fgetc(stdin);//버퍼에 들어간 개행문자 지우기
  for(int i=1;i<=size;i++){
    for(int j=1;j<=size;j++){
      arr[i][j]=fgetc(stdin);
    }
    fgetc(stdin);//버퍼에 들어간 개행문자 지우기
  }
    CandyGame(arr,size);
    if(pq.top()+1==1)
    cout<<0;
  else
   cout<<pq.top()+1;
  return 0;
}
