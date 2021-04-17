#include <iostream>
#include <queue>
#include <cstdio>
#define MAX 1501
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int main(void){
  long long int n,temp;
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&temp);
      if(q.size()<n){
        q.push(temp);
      }
      else{
        q.push(temp);
        q.pop();
      }
    }
  }
  cout<<q.top();
  return 0;
}
