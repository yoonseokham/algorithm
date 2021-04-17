#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int,int> > v[10001];
int dp[10001]={0};
int LargeChild(int num){
  vector<int> large;
  if(dp[num]!=0)
    return dp[num];
  if(v[num].size()==0)
    return 0;
  else {
    for(int i=0;i<v[num].size();i++){
      large.push_back(v[num][i].second+LargeChild(v[num][i].first));
    }
    sort(large.begin(),large.end(),greater<int>());
    return dp[num]=large[0];
  }
}
int firstCall(int num){
  int sum=0;
  vector<int> large;
  if(v[num].size()==0)
    return 0;
  else{
    for(int i=0;i<v[num].size();i++){
      large.push_back(v[num][i].second+LargeChild(v[num][i].first));
    }
    sort(large.begin(),large.end(),greater<int>());
    return large[0]+large[1];
  }
}

int main(void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n,temp[3];
  vector <int> answer;
  cin>>n;
  for(int i=0;i<n-1;i++){
    cin>>temp[0]>>temp[1]>>temp[2];
    v[temp[0]].push_back(make_pair(temp[1],temp[2]));
  }
  for(int i=0;i<n;i++){
    answer.push_back(firstCall(i+1));
  }
  sort(answer.begin(),answer.end(),greater <int> ());
  cout<<answer[0];
  return 0;
}
