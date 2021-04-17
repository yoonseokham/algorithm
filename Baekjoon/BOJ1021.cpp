#include <deque>
#include <iostream>
using namespace std;
deque <int> dq;
int arr[50]={0};
void Operate(int i){
  int temp;
  if(i==1)
    dq.pop_front();
  else if(i==2){
    temp=dq.front();
    dq.pop_front();
    dq.push_back(temp);
  }
  else {
    temp=dq.back();
    dq.pop_back();
    dq.push_front(temp);
  }
}
int findElement(int num){
  for(int i=0;i<dq.size();i++){
    if(dq[i]==num)
      return i;
  }
  return -1;
}
int NumOfOperate23(int m){
int count=0;
  for(int i=0;i<m;i++){
    int temp=findElement(arr[i]);
    if(temp<=dq.size()/2){
      for(int j=0;j<temp;j++)
        Operate(2);
      count+=temp;
    }
    else{
      for(int j=0;j<dq.size()-temp;j++)
        Operate(3);
      count+=dq.size()-temp;
    }
    Operate(1);
  }
  return count;
}
int main(void){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
    cin>>arr[i];
  for(int i=1;i<=n;i++)
    dq.push_back(i);
  cout<<NumOfOperate23(m);
  return 0;
}
