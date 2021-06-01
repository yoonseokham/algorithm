#include <bits/stdc++.h>
using namespace std;
int findLatestUse(unordered_set<int> &multiTab,vector<int> &device,int i,int n){
  unordered_set<int> usingTab=multiTab;
  unordered_set<int> minus=multiTab;
  int end=-1;
  for(int j=i;j<int(device.size());j++){
    if(usingTab.find(device[j])!=usingTab.end()&& minus.size()>0){
      end=device[j];
      if(minus.find(device[j])!=minus.end()) minus.erase(minus.find(device[j]));
    }
  }
  if(minus.size()==0) return end;
  else return *minus.begin();
}
int main(void){
  int n,k,x,popCount=0;
  cin>>n>>k;
  vector<int> device(k,0);
  unordered_set<int> multiTab;
  for(int i=0;i<k;i++) cin>>device[i];
  for(int i=0;i<k;i++){
    if(multiTab.find(device[i])!=multiTab.end()) continue;
    else if(multiTab.size()<n) multiTab.insert(device[i]);
    else{
      popCount++;
      x=findLatestUse(multiTab,device,i+1,n);
      multiTab.erase(multiTab.find(x));
      multiTab.insert(device[i]);
    }
  }
  cout<<popCount;
  return 0;
}
