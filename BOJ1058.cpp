#include <iostream>
#include <vector>
#define MAX 51
using namespace std;
bool visit[MAX]={0};
bool arr[MAX][MAX]={0};
int counter=0;
int secondCall=1;
void initer(int indx,int n){
   counter=0;
   secondCall=1;
  for(int i=0;i<MAX;i++)
    visit[i]=false;
  visit[indx]=true;
}
int friendCounter(int indx,int n,int secondCall=1){
  for(int i=1;i<=n;i++){
    if(arr[indx][i]==true){
      if(visit[i]==false){
        counter++;
        visit[i]=true;}
        if(secondCall==1){
          friendCounter( i, n,0);
        }
    }
  }
  return counter;
}
int main(void){
int n,temp,max=0;
cin>>n;
fgetc(stdin);
for(int  i=1;i<=n;i++){
  for(int j=1;j<=n;j++){
    temp=fgetc(stdin);
    if(temp=='Y')
      arr[i][j]=1;
  }
  fgetc(stdin);
}
for(int i=1;i<=n;i++){
  initer(i,n);
  temp=friendCounter(i,n);
  max=max> temp ? max:temp;
}

cout<<max;
  return 0;
}
