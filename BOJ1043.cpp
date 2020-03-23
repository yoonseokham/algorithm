#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 52
using namespace std;
vector <int> party[MAX];
vector <int> truth;
bool truthKnower(int k){//k번째파티에서 사실을 아는 놈이잇으면 true
  for(int i=0;i<truth.size();i++){
    for(int j=0;j<party[k].size();j++){
      if(truth.at(i)==party[k].at(j))
        return true;
    }
  }
  return false;
}
void truthMaker(int k){
  if(truthKnower(k)){
    for(int j=0;j<party[k].size();j++){
      truth.push_back(party[k][j]);
    }
    sort(truth.begin(),truth.end());
    truth.erase(unique(truth.begin(),truth.end()),truth.end());
  }
}
int fakeTelling(int m){
int fake=0;
  for(int i=1;i<=m;i++){
    if(truthKnower(i)){
      truthMaker(i);
    }
    else
      fake++;
  }
  return fake;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,trueNum,temp,temp2;
  cin>>n>>m;
  cin>>trueNum;
  for(int i=0;i<trueNum;i++){
    cin>>temp;
    truth.push_back(temp);
  }
  for(int j=1;j<=m;j++){
  cin>>temp;
  for(int i=0;i<temp;i++){
    cin>>temp2;
    party[j].push_back(temp2);
  }
}
sort(truth.begin(),truth.end());
for(int i=1;i<=m;i++){
  sort(party[i].begin(),party[i].end());
}
for(int i=0;i<=MAX;i++)
  fakeTelling(m);
cout<<fakeTelling(m);
  return 0;
}
