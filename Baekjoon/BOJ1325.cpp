#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v[10001];
void dfs(int num,bool visit []){
  for(int i=0;i<v[num].size();i++){
    if(visit[v[num][i]]==false){
      visit[v[num][i]]=true;
      dfs(v[num][i],visit);
    }
  }
}
void dfsall(int n){
  vector <pair<int,int> > answer;
  vector <int> real_answer;
  int cnt=0,i=0;
  for(int i=1;i<=n;i++){
    cnt=0;
    bool visit [10001]={false};
    visit[i]=true;
    dfs(i,visit);
    for(int j=1;j<=n;j++){
      if(visit[j])
        cnt++;
    }
    answer.push_back(make_pair(cnt,i));
  }
  sort(answer.begin(),answer.end(),greater<pair<int,int> > ());
  while(i<answer.size()){
    real_answer.push_back(answer[i].second);
    if(i+1<answer.size()&&answer[i].first>answer[i+1].first)
      break;
    i++;
  }
  sort(real_answer.begin(),real_answer.end());
  for(int i=0;i<real_answer.size();i++){
    cout<<real_answer[i]<<" ";
  }
}
int main(void){
  int n,m,temp[2];
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>temp[0]>>temp[1];
    v[temp[1]].push_back(temp[0]);
  }
  dfsall(n);
  return 0;
}
