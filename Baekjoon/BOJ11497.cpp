#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int maxDiv(vector <int> & a,int n){
  int div=abs(a[0]-a[n-1]);
  for(int i=0;i<n-1;i++){
    if(div<abs(a[i]-a[i+1])) div=abs(a[i]-a[i+1]);
  }
  return div;
}
vector <int> vecMaker(int n,vector <int> &num ){
  vector<int> newVec(n,0);
  int increaseJ=0,decreaseJ=n-1;
  for(int i=0;i<n;i++){
    if(i%2==0)
      newVec[increaseJ++]=num[i];
    else
      newVec[decreaseJ--]=num[i];
  }
  return newVec;
}
int main(void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n,temp,testcase;
  cin >>testcase;
  for(int j=0;j<testcase;j++){
    vector <int> num;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>temp;
      num.push_back(temp);
    }
    sort(num.begin(),num.end());
    num=vecMaker(n,num);
    cout<<maxDiv(num,n)<<"\n";
  }
  return 0;
}
