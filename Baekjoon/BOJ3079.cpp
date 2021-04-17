#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// long long departure[100000];
vector <long long> departure;
vector <long long> answer;
bool SpreadAble(long long n,long long m,long long mid){
  for(int i=0;i<n;i++){
    m-=mid/departure[i];
  }
  return (m<=0);
}
long long BinarySearch(long long n,long long m){
  long long low=departure[0],high=departure[n-1]*m,mid;
  while(low<=high){
    mid=(low+high)/2;
    if(SpreadAble(n,m,mid)){
      answer.push_back(mid);
      high=mid-1;
    }
    else{
    low=mid+1;
    }
  }
  sort(answer.begin(),answer.end());
  return answer[0];
}
int main(void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  long long n,m,temp;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>temp;
    departure.push_back(temp);
  }
  sort(departure.begin(),departure.end());
  cout<<BinarySearch(n,m);
  return 0;
}
