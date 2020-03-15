#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;
int Ti[MAX]={0};
int Pi[MAX]={0};
int max_p=0;

void go(int n,int indx=1,int sum=0){
  if(indx==n+1){
    max_p=max(max_p,sum);
    return;
  }
  if(indx>n+1)
    return;
    go(n,indx+1,sum);
    go(n,indx+Ti[indx],sum+Pi[indx]);
}
int main(void){
  int n;
  cin>>n;
  Ti[0]=1;
  for(int i=1;i<=n;i++)
    cin>>Ti[i]>>Pi[i];
  go(n);
  cout<<max_p;
  return 0;
}
