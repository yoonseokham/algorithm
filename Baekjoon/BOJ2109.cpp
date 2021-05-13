#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n,temp1,temp2,answer=0,popCount=0;
  unordered_map<int,vector<int>> pay;
  priority_queue <int> pq;
  set<int> key;
  cin>>n;
  key.insert(0);
  pay[0].push_back(0);
  for(int i=0;i<n;i++){
    cin>>temp1>>temp2;
    key.insert(temp2);
    pay[temp2].push_back(temp1);
  }
  for(int i:key) sort(pay[i].begin(),pay[i].end(),greater<int>());
  for(auto iter=key.rbegin();iter!=key.rend();++iter){
      if(*iter==0)  continue;
      for(int i=0;i<int(pay[*iter].size());i++) pq.push(pay[*iter][i]);
      popCount=min(*iter-*next(iter),int(pq.size()));
      for(int i=0;i<popCount;i++){
        answer+=pq.top();
        pq.pop();
      }
  }
  cout<<answer;
  return 0;
}
