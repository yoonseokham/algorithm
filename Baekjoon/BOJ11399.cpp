#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001]={0};
int atm(int n){
  int sum=arr[0];
  for(int i=1;i<n;i++){
    arr[i]+=arr[i-1];
    sum+=arr[i];
  }
  return sum;
}
int main(void){
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>arr[i];
  sort(arr,arr+n);
  cout<<atm(n);
  return 0;
}
