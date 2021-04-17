#include <iostream>
#define MAX 51
using namespace std;
int arr[51][51]={0};
int big_Rec(int n,int m){
  int count=0;
  int small= n<m ? n:m;
  for(int k=1;k<small;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(i+k<n&&j+k<m){
          if(arr[i][j]==arr[i][j+k]&&arr[i+k][j]==arr[i+k][j+k]&&arr[i][j]==arr[i+k][j])
            count=k;
        }
      }
    }
  }
  return (count+1)*(count+1);
}
int main(void){
  int n,m;
  cin>>n>>m;
  fgetc(stdin);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      arr[i][j]=fgetc(stdin);
    fgetc(stdin);
  }
  cout<<big_Rec(n,m);
  return 0;
}
