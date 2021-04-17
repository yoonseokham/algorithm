//BOJ N과M (3) 15651번
#include <iostream>
#include <vector>
#define MAX 8
using namespace std;
vector<int> v;
bool visited[MAX]={0};
void nPm(int n,int m,int cnt=0) {
  if(cnt==m){
    for(int i=0;i<v.size();i++)
      cout<<v.at(i)<<" ";
    cout<<"\n";
  }
  else{
    for(int i=1;i<=n;i++){
      //if(visited[i]==false){
        v.push_back(i);
        //visited[i]=true;
        nPm(n,m,cnt+1);
        v.pop_back();
      //  visited[i]=false;
    //  }
    }
  }
}
int main(void){
  int n,m;
  cin>>n>>m;
  nPm(n,m);
}
