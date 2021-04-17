#include <iostream>
using namespace std;
long long arr[11]={0};
long long NumOfCoin(long long n,long long k){
long long count=0;
long long money=k;
long long i=n;
  while(money>0&&i>0){
    if(arr[i]>money){
      i--;
    }
    else{
      money-=arr[i];
      count++;
    }
  }
  return count;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n=0;
  long long k=0;
  cin>>n>>k;
  for(long long i=1;i<=n;i++)
    cin>>arr[i];
  cout<<NumOfCoin(n,k);
  return 0;
}
