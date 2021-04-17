#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// vector <int> num;
vector <int> Postive;
vector <int> negative;
int maxNum(int n,vector <int> & num){
  int sum=0,i;
  for(i=0;i<n-1;){
    int temp2=num[i]+num[i+1],temp1=num[i]*num[i+1];
    if(temp2>temp1){
      sum+=num[i];
      i++;
    }
    else{
      sum+=temp1;
      i+=2;
    }
  }
  if(i==n-1)
    sum+=num[i];
  return sum;
}
int main(void){
  int n,temp;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    if(temp>0)
      Postive.push_back(temp);
    else
      negative.push_back(temp);
  }
  sort(Postive.begin(),Postive.end(),greater <int>());
  sort(negative.begin(),negative.end());
  cout<<maxNum(Postive.size(),Postive)+maxNum(negative.size(),negative);
  return  0;
}
