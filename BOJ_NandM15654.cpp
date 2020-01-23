//BOJ N과M (5) 15654번
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;
vector<int> v;
bool visited[MAX]={0};
int arr[MAX]={0};
void nPm(int n,int m,int cnt=0) {
  if(cnt==m){
    for(int i=0;i<v.size();i++)
      cout<<v.at(i)<<" ";
    cout<<"\n";
  }
  else{
    for(int i=1;i<=n;i++){
        if(visited[i]==false){
        visited[i]=true;
        v.push_back(arr[i]);
        nPm(n,m,cnt+1);
        v.pop_back();
        visited[i]=false;
      }
    }
  }
}
int main(void){
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
  }
  sort(arr+1,arr+n+1);
  nPm(n,m);
}
