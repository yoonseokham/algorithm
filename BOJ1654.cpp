#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
vector<long long> v;
vector <long long> answer;
int LaneCount(long long k,long long mid){
  long long cnt=0;
    for(int i=0;i<v.size();i++){
      cnt+=v[i]/mid;
    }
    if(cnt<k) return -1; //너무큼
    answer.push_back(mid);
    return 0;
}
void BinarySearch(long long k,long long min){
  long long start=1,end=min,mid,temp;
    while(start<=end){
      mid=(end+start)/2;
      temp=LaneCount(k,mid);
      if(temp==-1)
        end=mid-1;
      else
        start=mid+1;
  }
}
int main(void){
  long long n,k,temp,max=0;
  cin>>n>>k;
  for(long long i=0;i<n;i++){
    cin>>temp;
    max=max<temp?temp:max;
    v.push_back(temp);
  }
  BinarySearch(k,max);
  sort(answer.begin(),answer.end());
  cout<<answer[answer.size()-1];
  return 0;
}
