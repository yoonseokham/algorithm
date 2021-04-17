#include <bits/stdc++.h>
using namespace std;
int parentReturn(vector<pair<int,vector<int> > > &v,int child){
  return v[child].first;
}
int BFS_search(vector<pair<int,vector<int> > > &v,int child1,int child2){
  set<int> parent1;
  set<int> parent2;
  parent1.insert(child1);
  parent2.insert(child2);
    while(true){
      if(parent2.find(child1)!=parent2.end()) return child1;
      else if(parent1.find(child2)!=parent1.end()) return child2;
      if(child1!=-1){
        child1=parentReturn(v,child1);
        parent1.insert(child1);
      }
      if(child2!=-1){
      child2=parentReturn(v,child2);
      parent2.insert(child2);
      }
    }
}
int main(void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int testcase,n,parent,child;
  cin>>testcase;
  for(int j=0;j<testcase;j++){
    cin>>n;
    vector<pair<int,vector<int> > > v(n+1,{-1,vector<int>(0)});
    for(int i=0;i<n-1;i++){
      cin>>parent>>child;
      v[parent].second.push_back(child);
      v[child].first=parent;
    }
    cin>>parent>>child;
    cout<<BFS_search(v,parent,child)<<"\n";
  }

  return 0;
}
