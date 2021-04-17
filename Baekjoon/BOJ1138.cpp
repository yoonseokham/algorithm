#include <iostream>
#include <vector>
using namespace std;
int memory[10]={0};
bool visit[10]={false};
vector <int> waitQueue;
bool QueueCheck(int n){
  int arr[10]={0};
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(waitQueue[i]<waitQueue[j])
        arr[waitQueue[i]-1]++;
    }
  }
  for(int i=0;i<n;i++){
    if(arr[i]!=memory[i])
      return false;
  }
  return true;
}
void Permutation(int n){
  if(waitQueue.size()==n){
    if(QueueCheck(n)){
      for(int i=0;i<n;i++){
        cout<<waitQueue[i]<<" ";
      }
    }
    return;
  }
  else{
    for(int i=0;i<n;i++){
      if(visit[i]==false){
        waitQueue.push_back(i+1);
        visit[i]=true;
        Permutation(n);
        waitQueue.pop_back();
        visit[i]=false;
      }
    }
  }
}
int main(void){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>memory[i];
  }
  Permutation(n);
  return 0;
}
