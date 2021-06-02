#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n,day,score,sum=0,homeWorkPick;
  cin>>n;
  set<int> key;
  key.insert(0);
  unordered_map<int,vector<int>> homeWork;
  priority_queue<int> pq;
  for(int i=0;i<n;i++) {
    cin>>day>>score;
    key.insert(day);
    homeWork[day].push_back(score);}
  for(auto iter=key.rbegin();iter!=key.rend();++iter){
    if(*iter==0) break;
    for(int i:homeWork[*iter]) pq.push(i);
    homeWorkPick=min(int(pq.size()),*iter-*next(iter));
    for(int i=0;i<homeWorkPick;i++) {
      sum+=pq.top();
      pq.pop();}
  }
  cout<<sum;
  return 0;
}
