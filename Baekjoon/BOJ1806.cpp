#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> num;
vector <int> gap;
int SmakeLength(int n,int s){
int LPoint=0,RPoint=1,sum=num[0];
  while(RPoint<=n&&RPoint>LPoint){
    if(sum<s){
      sum+=num[RPoint];
      RPoint++;
      if(sum>=s)
        gap.push_back(RPoint-LPoint);
    }
    else{
      sum-=num[LPoint];
      LPoint++;
      if(sum>=s)
        gap.push_back(RPoint-LPoint);
    }
  }
  if(gap.size()==0)
    return 0;
  sort(gap.begin(),gap.end());
  return gap[0];
}
int main(void){
  int n,s,temp;
  cin>>n>>s;
  for(int i=0;i<n;i++){
    cin>>temp;
    num.push_back(temp);
    if(temp>=s)
    {
      cout<<1;
      return 0;
    }
  }
  cout<<SmakeLength(n,s);
  return 0;
}
