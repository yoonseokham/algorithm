#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector <pair<int,int> > v;
priority_queue < pair<int,int> , vector <pair<int,int>>,greater <pair<int,int> > >pq;

int main(void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n,start,end,preEnd=0,cnt=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>start>>end;
    v.push_back({start,end});
  }
  sort(v.begin(),v.end());
  pq.push({v[0].second,v[0].first});
  for(int i=1;i<v.size();i++){
    if(pq.top().first<=v[i].first){
      pq.pop();
      // pq.push({v[i].second,v[i].first});
    }
    pq.push({v[i].second,v[i].first});
    
  }
  cout<<pq.size();
  return 0;
}
