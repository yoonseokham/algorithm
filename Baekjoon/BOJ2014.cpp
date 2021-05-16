#include <bits/stdc++.h>
using namespace std;
int main(void){
  unsigned int k,n,curPrime=0,curNum=0;
  set<unsigned int> duplicate;
  cin>>k>>n;
  vector<unsigned int> prime(k,0);
  priority_queue<unsigned int,vector<unsigned int>,greater<unsigned int>> pq;
  for(unsigned int i=0;i<k;i++) {
    cin>>prime[i];
    pq.push(prime[i]);
  }
  sort(prime.begin(),prime.end());
  while(curPrime<n){
    curNum=pq.top();
    pq.pop();
    if(duplicate.find(curNum)!=duplicate.end()) continue;
    duplicate.insert(curNum);
    curPrime++;
    for(unsigned int i:prime) {
      if((long long)((long long)curNum*(long long)i)>INT_MAX) continue;
      pq.push(curNum*i);
    }
  }
  cout<<curNum;
  return 0;
}
