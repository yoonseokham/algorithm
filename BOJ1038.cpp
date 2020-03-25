#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10
using namespace std;
int arr[10]={0,1,2,3,4,5,6,7,8,9};
bool visited[10]={0};
vector <int> v;
int totalAmount=0;
void DFS(int cnt=0,int lenght=1,int n=0){
  if(cnt==lenght){
    totalAmount++;
    if(n==totalAmount)
    {
      for(int j=1;j<v.size();j++)
        cout<<v[j];
      return;
    }
  }
  else{
    for(int i=0;i<10;i++){
      if(!visited[i]){
        if(arr[i]<v.back()){
        visited[i]=true;
        v.push_back(arr[i]);
        DFS(cnt+1,lenght,n);
        visited[i]=false;
        v.pop_back();
      }
      }
    }
  }
}
int main(void) {
  v.push_back(10);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  if(n>1022){
    cout<<-1;
    return 0;
  }
  for(int i=1;i<=10;i++){
    DFS(0,i,n+1);
    for(int j=0;j<10;j++)
      visited[j]=0;
  }
  return 0;
}
