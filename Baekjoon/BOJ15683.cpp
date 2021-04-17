#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std;
int arr[8][8]={0};
int maped[8][8]={0};
int global_sum=2100000000;
typedef pair <int,int> Pair;
vector <int> a;
vector <pair < pair <int,int>, pair <int,int> > > v;
enum direction{
  none=0,
  north=1,
  east=2,
  south=3,
  west=4
};
void watchZoneIniter(int n,int m,Pair location,int direct){ // 주어진 방향에 대해서 watchZone을 표기해줌
  int indx=location.first,jndx=location.second;
  switch (direct) {//주어진 방향에 대해
    case 1:
      for(int i =indx;i>=0;i--){
        if(maped[i][jndx]==6)
          break;
        else if(maped[i][jndx]==0){

          maped[i][jndx]=-1;}
      }
    break;
    case 2:
    for(int j =jndx;j<m;j++){
      if(maped[indx][j]==6)
        break;
      else if(maped[indx][j]==0)
        maped[indx][j]=-1;
    }
    break;
    case 3:
    for(int i =indx;i<n;i++){
      if(maped[i][jndx]==6)
        break;
      else if(maped[i][jndx]==0)
        maped[i][jndx]=-1;
    }
    break;
    case 4:
    for(int j =jndx;j>=0;j--){
      if(maped[indx][j]==6)
        break;
      else if(maped[indx][j]==0)
        maped[indx][j]=-1;
    }
    break;
  }
}
int direction_changer2(int direct){
direct++;
  if(direct==5)
    return north;
return direct;
}
void watch_initer(int n,int m,pair<Pair,Pair> cctv_info){
  switch (cctv_info.second.first) {//cctv type에 대해서
    case 1:
    watchZoneIniter(n,m,cctv_info.first,cctv_info.second.second);
    break;
    case 2:
    watchZoneIniter(n,m,cctv_info.first,cctv_info.second.second);
    watchZoneIniter(n,m,cctv_info.first,direction_changer2(direction_changer2(cctv_info.second.second)));
    break;
    case 3:
    watchZoneIniter(n,m,cctv_info.first,cctv_info.second.second);
    watchZoneIniter(n,m,cctv_info.first,direction_changer2(cctv_info.second.second));
    break;
    case 4:
    watchZoneIniter(n,m,cctv_info.first,cctv_info.second.second);
    watchZoneIniter(n,m,cctv_info.first,direction_changer2(cctv_info.second.second));
    watchZoneIniter(n,m,cctv_info.first,direction_changer2(direction_changer2(cctv_info.second.second)));
    break;
  }
}
void direction_changer(int& direct){
  direct++;
  if(direct==5)
    direct=north;
}

int zeroSum(int n ,int m){
  int sum=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(maped[i][j]==0){
          sum++;
        }
      }
    }
    return sum;
}
void Direction_generator(int n,int m,int indx=0){
  if(indx==v.size()){
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        maped[i][j]=arr[i][j];
        }
      }
      for(int i=0;i<v.size();i++)
        watch_initer(n,m,v[i]);
    global_sum=min(zeroSum(n,m),global_sum);
    return;
  }
  for(int i=0;i<4;i++){
      direction_changer(v[indx].second.second);
      Direction_generator(n,m,indx+1);
  }
}

int main(void){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>arr[i][j];
      maped[i][j]=arr[i][j];
      if(arr[i][j]&&arr[i][j]!=6&&arr[i][j]!=5)
          v.push_back({{i,j},{arr[i][j],0}});
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(maped[i][j]==5){
        for(int k=1;k<5;k++)
          watchZoneIniter(n,m,{i,j},k);
      }
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        arr[i][j]=maped[i][j];
        }
      }
  Direction_generator(n,m);
  cout<<global_sum;
  return 0;
}
