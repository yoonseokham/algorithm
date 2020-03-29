#include <iostream>
#include <vector>
#define MAX 202
using namespace std;
bool arr[MAX][MAX]={0};
int componet[MAX*MAX]={0};
int plan[1001]={0};
void initComponet(void){
  for(int i=0;i<MAX*MAX;i++)
    componet[i]=i;
}
int find(int x){
  if(componet[x]==x)
    return x;
  else
    return componet[x]=find(componet[x]);
}
void unionComponet(int x,int y){
  x=find(x);
  y=find(y);

  if(x==y)
    return;
  else{
    if(x>y)
      componet[x]=y;
    else
      componet[y]=x;
  }
}
int main(void){
  int n,m;
  cin>>n>>m;
   initComponet();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>arr[i][j];
      if(arr[i][j])
        unionComponet(i,j);}
  }
  for(int i=0;i<m;i++)
    cin>>plan[i];
  for(int i=0;i<m-1;i++){
    if(find(plan[i])!=find(plan[i+1])){
      cout<<"NO";
      return 0;
    }
  }
  cout<<"YES";
  return 0;
}
