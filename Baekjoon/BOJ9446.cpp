#include <bits/stdc++.h>
using namespace std;
void dfsTraval(vector<int>& people,vector<bool> &visit,int start,int curI){
  if(visit[curI]==true) return;
  if(people[curI]==start){
    visit[curI]=true;
    return;
  }
  else{

  }
}
int main(void){
  int testcase,n,temp;
  cin>>testcase;
  for(int i=0;i<testcase;i++){
    vector<int> people;
    vector<bool> visit;

    cin>>n;
    for(int j=0;j<n;j++){
      cin>>temp;
      people.push_back(temp-1);
      visit.push_back(false);
    }
    for(int j=0;j<n;j++){

    }
  }
}
