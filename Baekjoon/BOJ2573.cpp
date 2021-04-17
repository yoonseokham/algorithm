#include <iostream>
#define MAX 302
using namespace std;
int arr[MAX][MAX]={0};
int year=0;
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
int minus_s(int a,int b){
  if(a-b>=0)
    return a-b;
  else
    return 0;
}
void one_year_pass(int n,int m){
  int count=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(arr[i][j]==-1)
        continue;
      else{
        count=0;
        for(int k=0;k<4;k++){
          if(arr[i+di[k]][j+dj[k]]==-1)
            count++;
        }
        arr[i][j]=minus_s(arr[i][j],count);
      }
    }
  }
  year++;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(arr[i][j]==0)
        arr[i][j]=-1;
    }
  }
}
void DFS(int(*brr)[MAX],int indx,int jndx){
  for(int k=0;k<4;k++){
    if(brr[indx+di[k]][jndx+dj[k]]>0){
      brr[indx+di[k]][jndx+dj[k]]=-1;
      DFS(brr,indx+di[k],jndx+dj[k]);
    }
  }
}
bool divide_iceberg(int n,int m){
  int brr[MAX][MAX]={0};
  int divide=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      brr[i][j]=arr[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(brr[i][j]==-1)
        continue;
      else{
        DFS(brr,i,j);
        divide++;
      }
    }
  }
  if(divide==1)
    return false;
  else
    return true;
}
int main(void){
  int n,m;
  cin>>n>>m;
  int temp;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>temp;
      if(temp==0)
        arr[i][j]=-1;
      else
        arr[i][j]=temp;
    }
  }
  while(!divide_iceberg(n,m)){
    one_year_pass(n,m);
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(arr[i][j]!=-1){
        cout<<year;
        return 0;
      }
    }
  }
 cout<<0;
  return 0;
}
