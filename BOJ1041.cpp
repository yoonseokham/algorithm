#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[7]={0};
bool touchEachother(int i,int j){
  if(i==j)
    return false;
  int big=i>j?i:j;
  int small=i>j?j:i;
  if(big==5&&small==2)  return false;
  if(big==4&&small==3)  return false;
  if(big==6&&small==1)  return false;
  return true;
}
long long answer(int num){
  vector <int> n[3];
  for(int i=1;i<=5;i++){
    n[0].push_back(i);
    for(int j=i+1;j<=6;j++){
      if(touchEachother(i,j))
        n[1].push_back(a[i]+a[j]);
    }
  }
  for(int i=1;i<=4;i++){
    for(int j=i+1;j<=5;j++){
      for(int k=j+1;k<=6;k++){
        if(touchEachother(i,j)&&touchEachother(j,k)&&touchEachother(i,k))
          n[2].push_back(a[i]+a[j]+a[k]);
      }
    }
  }
  n[0].push_back(6);
  for(int i=0;i<3;i++){
    sort(n[i].begin(),n[i].end());
  }
   if(n>=2)
    return n[0][0]*(num-2)*(num-1)*4+n[0][0]*(num-2)*(num-2)+ n[1][0]*(num-2)*4 +n[1][0]*(num-1)*4+4*n[2][0];
   if(n==1)
    return n[0][1]+n[0][2]+n[0][3]+n[0][4]+n[0][0];
  return 0;
}
int main(void){
  int n;
  cin>>n;
  for(int i=1;i<7;i++)
    cin>>a[i];
  cout<<answer(n);
  return 0;
}
