#include <iostream>
#include <unordered_set>
using namespace std;
int k_finder(unordered_set<int>&obstacle,int n,int z){
  int k=0;
  int start=1;
  while(true){
  int visit[1001]={false};
  start=1;
  k++;
  while(obstacle.find(start)==obstacle.end()&&!visit[start]){
    visit[start]=true;
    if(start==z) return k;
    start+=k;
    if(start>n) start%=n;
   }
 }
}
int main(void){
 int n,z,m,temp;
 unordered_set<int> obstacle;
 ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 cin>>n>>z>>m;
 for(int i=0;i<m;i++){
   cin>>temp;
   obstacle.insert(temp);
 }
 if(obstacle.size()==n-2) cout<<z-1;
 else cout<<k_finder(obstacle,n,z);
  return 0;
}
