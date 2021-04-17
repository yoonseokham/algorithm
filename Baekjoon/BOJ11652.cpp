#include <map>
#include <iostream>
using namespace std;

int main(void){
  map<long long,int> m;
  long long n,temp;
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>temp;
    if(m.find(temp)==m.end()) m[temp]=1;
    else m[temp]++;
  }
  int Max=0;
  long long Index=0;
  for(map<long long,int>::iterator it=m.begin();it!=m.end();++it){
      if(it->second>Max) {
        Max=it->second;
        Index=it->first;
      }
      // cout<<it->first<<" "<<it->second<<"\n";
      }
  cout<<Index;
  return 0;
}
