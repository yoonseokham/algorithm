#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
pair<int,int> arr[100001];
bool cmp(const pair<int,int>& a,const pair<int,int>& b){
  if(a.second<b.second)
    return true;
  else if(a.second==b.second){
    if(a.first<b.first)
      return true;
    else
      return false;
  }
  else
    return false;
}
int numOfConference_return(int n){
int endTime=0;
int numOfConference=0;
  for(int i=0;i<n;i++){
    if(endTime<=arr[i].first){
      numOfConference++;
      endTime=arr[i].second;
    }
  }
  return numOfConference;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i].first>>arr[i].second;
  }
  sort(arr,arr+n,cmp);
  cout<<numOfConference_return(n);
  return 0;
}
