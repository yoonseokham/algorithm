#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;
vector <pair <int,int> > house;
vector <pair <int,int> > chicken_house;
vector <int> comdination;
bool visit_for_backTrack[14]={0};
int global_chicken_distance=INF;

int abs(int a,int b){
  return a-b>0 ? a-b:b-a;
}
int distanceCalculater(pair<int ,int> a, pair <int,int> b){
  return abs(a.first,b.first)+abs(a.second,b.second);
}
void BackTrack(int n,int m,int indx=0,int cnt=0){
  if(m==cnt){
    int small,temp=0,local_chicken_distance=0;
    for(int i=0;i<house.size();i++){
       small=INF;
      for(int j=0;j<comdination.size();j++){
        temp=distanceCalculater(house[i],chicken_house[comdination[j]]);
        small=temp<small ? temp :small;
      }
      local_chicken_distance+=small;
    }
    global_chicken_distance=global_chicken_distance < local_chicken_distance ? global_chicken_distance:local_chicken_distance;
  }
  else{
    for(int i=indx;i<chicken_house.size();i++){
      if(visit_for_backTrack[i]==false){
        visit_for_backTrack[i]=true;
        comdination.push_back(i);
        BackTrack(n,m,i+1,cnt+1);
        visit_for_backTrack[i]=false;
        comdination.pop_back();

      }
    }
  }
}
int main(void){
  int n,m,memo;
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>memo;
      if(memo==1)
        house.push_back({i,j});
      else if(memo==2)
        chicken_house.push_back({i,j});
    }
  }
  BackTrack(n,m);
  cout<<global_chicken_distance;
  return 0;
}
