//BOJ N과M (4) 15652번
#include <iostream>
#include <vector>
#define MAX 8
using namespace std;
vector<int> v;
void nPm(int indx,int n,int m,int cnt=0) {
  if(cnt==m){
    for(int i=0;i<v.size();i++)
      cout<<v.at(i)<<" ";
    cout<<"\n";
  }
  else{
    for(int i=indx;i<=n;i++){
        v.push_back(i);
        nPm(i,n,m,cnt+1);
        v.pop_back();
    }
  }
}
int main(void){
  int n,m;
  cin>>n>>m;
  nPm(1,n,m);
}
