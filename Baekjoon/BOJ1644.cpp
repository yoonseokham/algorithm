#include <bits/stdc++.h>
using namespace std;

vector<int> eratos(int n){
  vector<bool> prime(n+1,true);
  vector<int> primeOnly;
  prime[0]=false;
  prime[1]=false;
  for(int i=2;i<=int(sqrt(n))+1;i++){
    if(prime[i])
      for(int j=2*i;j<=n;j+=i) prime[j]=false;
  }
  for(int i=2;i<=n;i++)
    if(prime[i]) primeOnly.push_back(i);
  return primeOnly;
}
int caterpiller(vector<int>& prime,int target){
  int answer=0;
  int start=0;
  int end=0;
  int sum=prime[start];
  while(end<prime.size()){
    if(sum<=target){
      if(sum==target) answer++;
      sum+=prime[++end];
    }
    else sum-=prime[start++];
  }
  return answer;
}
int main(void){
  int n;
  cin>>n;
  if(n==1) cout<<0;
  else{
  vector<int> prime=eratos(n);
  cout<<caterpiller(prime,n);}
}
