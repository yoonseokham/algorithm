#include <iostream>
using namespace std;
int numOfCount=0;
void n_sum(int n){
  if(n==0){
    numOfCount++;
    return;
  }
  else if(n<0)
    return;
  n_sum(n-1);
  n_sum(n-2);
  n_sum(n-3);
}
int main(void){
  int n,temp;
  cin>>n;
  for(int i=0;i<n;i++){
    numOfCount=0;
    cin>>temp;
    n_sum(temp);
    cout<<numOfCount<<"\n";
  }
  // n_sum(n);
  return 0;
}
