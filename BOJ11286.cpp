#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
priority_queue < pair <int,int> ,vector < pair <int ,int> > ,greater < pair <int ,int > > > pq;
int main(void){
  int n,temp;
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>temp;
    if(temp!=0) pq.push(make_pair(abs(temp),temp));
    else if(temp==0 && pq.size()!=0) {
      cout<<pq.top().second<<"\n";
      pq.pop();
    }
    else
      cout<<0<<"\n";
  }
}
