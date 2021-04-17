#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 11
using namespace std;
long long numOfOperater[4]={0};
long long arr[MAX]={0};
long long real_sum=-1000000001;
long long real_min=1000000001;
void permutationMaker(long long n,long long plus,long long minus,long long multi,long long divide,long long sum=0,long long i=0){
if(i>=n){
  return;
}
if(plus>0)
  permutationMaker(n,plus-1,minus,multi,divide, sum+arr[i+1],i+1);//,real_min=min(real_min,sum+arr[i+1]);
if(minus>0)
  permutationMaker(n,plus,minus-1,multi,divide, sum-arr[i+1],i+1);//,real_min=min(real_min,sum-arr[i+1]);
if(multi>0)
  permutationMaker(n,plus,minus,multi-1,divide, sum*arr[i+1],i+1);//,real_min=min(real_min,sum*arr[i+1]);
if(divide>0)
  permutationMaker(n,plus,minus,multi,divide-1, sum/arr[i+1],i+1);//,real_min=min(real_min,sum/arr[i+1]);
else if(plus==0&&minus==0&&multi==0&&divide==0){
  real_sum=max(real_sum,sum);
  real_min=min(real_min,sum);
}
}
int main(void){
  long long n;
  cin>>n;
  for(long long i=0;i<n;i++)
    cin>>arr[i];
  for(long long i=0;i<4;i++){
    cin>>numOfOperater[i];
  }
  long long plus=numOfOperater[0];
  long long minus=numOfOperater[1];
  long long multi=numOfOperater[2];
  long long divide=numOfOperater[3];
  permutationMaker(n,plus,minus,multi,divide,arr[0]);
  cout<<real_sum<<"\n"<<real_min;
  return 0;
}
