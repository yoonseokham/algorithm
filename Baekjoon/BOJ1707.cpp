#include <iostream>
#include <queue>

using namespace std;
priority_queue <int> q;
int arr[32]={0};
int minusI(int a){
  return -1*a;
}
int main(void){
  int n,temp,sum=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    q.push(minusI(temp));
  }
  int temp1,temp2;
  while(!q.empty()){
    if(q.size()!=1){
    temp1=minusI(q.top());
    q.pop();
    temp2=minusI(q.top());
    q.pop();
    sum+=temp1+temp2;
    q.push(minusI(temp1+temp2));
    }
    else{
      q.pop();
    }
  }
  cout<<sum;
	return 0;
	}
