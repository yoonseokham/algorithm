#include <set>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair <int,int> point;
point zero_near(vector <int>& v){
int start=0,end=v.size()-1,temp=0;
vector <pair <int,point > > answer;
  while(start<end){
    temp=v[start]+v[end];
    if(temp==0) return make_pair(v[start],v[end]);
    else if(temp>0){
      answer.push_back(make_pair(abs(temp),make_pair(v[start],v[end])));
      end--;
    }
    else{
      answer.push_back(make_pair(abs(temp),make_pair(v[start],v[end])));
      start++;
    }
  }
  sort(answer.begin(),answer.end());
  return make_pair(answer[0].second.first,answer[0].second.second);
}
int main(void){
  point answer;
  int n,temp;
  vector <int> v;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    v.push_back(temp);
  }
  sort(v.begin(),v.end());
  answer=zero_near(v);
  cout<<answer.first<<" "<<answer.second<<"\n";
  return 0;
}
