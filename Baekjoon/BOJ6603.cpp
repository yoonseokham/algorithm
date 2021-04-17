#include <iostream>
#include <vector>
#define MAX 14
using namespace std;
vector<int> v;
bool visited[MAX]={0};
int arr[MAX]={0};
void Lottery(int n,int indx=1,int cnt=0){
  if(cnt==6){
    for(int i=0;i<6;i++)
      cout<<v[i]<<" ";
    cout<<"\n";
  }
  else{
      for(int i=indx;i<=n;i++){
        if(!visited[i]){
          visited[i]=true;
          v.push_back(arr[i]);
          Lottery( n,i+1,cnt+1);
          visited[i]=false;
          v.pop_back();
        }
      }
  }
}
int main(void){
  int n=0;
  while(cin>>n){
    if(n==0)
      break;
    for(int i=1;i<=n;i++)
      cin>>arr[i];
    Lottery(n);
    cout<<"\n";
  }
  return 0;
}
