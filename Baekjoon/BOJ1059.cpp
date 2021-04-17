#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int NumOfGoodInterval(vector<int> &v,int temp){
int lastBackNum=v[0];
int lastStartNum=0;
int count=0;
  for(int i=0;i<v.size();i++){
    if(v[i]<temp){
      lastStartNum=v[i];
    }
    else{
      lastBackNum=v[i];
      break;
    }
  }
  for(int i=lastStartNum+1;i<=lastBackNum-2;i++){
    for(int j=i+1;j<=lastBackNum-1;j++){
      if(i<=temp&&temp<=j)
        count++;
    }
  }
  return count;
}
int main(void){
  vector <int> nums;
  int n,temp;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    nums.push_back(temp);
  }
  cin>>temp;
  sort(nums.begin(),nums.end());
  cout<<NumOfGoodInterval(nums,temp);
  return 0;

}
