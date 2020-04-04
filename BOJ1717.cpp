#include <iostream>
#define MAX 1000001
using namespace std;
int parent[MAX]={0};
int find(int x){
  if(parent[x]==x)
    return x;
  else
    return parent[x]=find(parent[x]);}

void unionIt(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y){
  }
  else{
    if(x>y)
      parent[x]=y;
    else
      parent[y]=x;
  }
}
bool unionDetect(int x,int y){
  x=find(x);
  y=find(y);

  if(x==y){
    return true;
  }
  else{
    return false;
  }
}
int main(void){
  ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
  int n,m,operation,temp_a,temp_b;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    parent[i]=i;
  for(int i=0;i<m;i++){
    cin>>operation>>temp_a>>temp_b;
    if(operation==0){
        unionIt(temp_a,temp_b);
    }
    else{
      if(unionDetect(temp_a,temp_b))
        cout<<"YES"<<"\n";
      else
        cout<<"NO"<<"\n";
    }
  }
  return 0;
}
