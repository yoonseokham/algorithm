#include <bits/stdc++.h>
using namespace std;

int main(void){
  set<int> s;
  int n,temp,cnt=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    s.insert(temp);
  }
  cin>>temp;
  for(auto iter=s.begin();iter!=s.end();++iter) if(s.find(temp-*iter)!=s.end()&&*iter!=temp) cnt++;
  cout<<cnt/2;
  return 0;
}
