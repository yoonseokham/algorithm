#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v;
int rainPuddle(int i,int w){
  int sum=0;
  vector<int> wall;
  for(int j=0;j<w;j++){
    if(v[i][j]==1)
      wall.push_back(j);
  }
  if(wall.size()>1){
  for(int k=0;k<wall.size()-1;k++)
      sum+=wall[k+1]-wall[k]-1;
    }
  return sum;
}
int main(void){
  int h,w,temp,sum=0;
  cin>>h>>w;
  v.assign(h,vector<int>(w,0));
  for(int j=0;j<w;j++){
    cin>>temp;
    for(int i=0;i<temp;i++)
      v[i][j]=1;
  }
  // for(int i=0;i<h;i++){
  //   for(int j=0;j<w;j++){
  //     cout<<v[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  for(int i=0;i<h;i++){
    sum+=rainPuddle(i,w);
  }
  cout<<sum;
  return 0;
}
