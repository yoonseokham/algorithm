#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
void brr_initer(int x,int* brr,int* arr,int n){
  for(int i=0,j=0;i<n;i++){
    if(i==x)
      continue;
    else
      brr[j++]=arr[i];
  }
}
void energy_collect(int n,int* arr,int energy=0){
  if(n==2){
    v.push_back(energy);
    return ;
  }
  else{
    for(int i=1;i<n-1;i++){
      int brr[10];
      brr_initer(i,brr,arr,n);
      energy_collect(n-1,brr,energy+arr[i-1]*arr[i+1]);

    }
  }
}
int main(void) {
  int n;
  cin>>n;
  int arr[10]={0};
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  energy_collect(n,arr);
  sort(v.begin(),v.end());
  cout<<v[v.size()-1];
  return 0;
}
