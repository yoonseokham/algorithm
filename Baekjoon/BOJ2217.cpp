#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001]={0};
int max_w=-1;
int max_weight(int n){
  for(int i=n-1,j=1;i>=0;i--,j++){
    max_w=max(max_w,arr[i]*j);
  }
  return max_w;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>arr[i];
  sort(arr,arr+n);
  cout<<max_weight(n);
  return 0;
}
