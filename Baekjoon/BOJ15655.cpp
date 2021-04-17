#include <iostream>
#include <vector>
#include <algorithm>
#define  MAX 8
using namespace std;
int arr[MAX]={0};
bool visit[MAX]={false};
vector<int> v;
void BackTrack(int n,int m,int start=0){
  if(v.size()==m){
    for(int i=0;i<m;i++)
      cout<<arr[v[i]]<<" ";
    cout<<"\n";
  }
  else{
    for(int i=start;i<n;i++){
      if(visit[i]==false){
        visit[i]=true;
        v.push_back(i);
        BackTrack(n,m,i+1);
        visit[i]=false;
        v.pop_back();
      }
    }
  }
}
int main(void){
  int n,m;
  cin>>n>>m;
  for (int i =0;i<n;i++)
    cin>>arr[i];
  sort(arr,arr+n);
  BackTrack(n,m);
  return 0;
}
