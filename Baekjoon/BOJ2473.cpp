#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

pair<int,int> closeToZero(vector<int>& liquor){
  int start=0,end=liquor.size()-1,answerStart,answerEnd,smallSum=2000000001;
  while(start<end){
    if(abs(liquor[start]+liquor[end])<smallSum){
      answerStart=start;
      answerEnd=end;
      smallSum=abs(liquor[start]+liquor[end]);
    }
    if(liquor[start]+liquor[end]>0) end--;
    else start++;
  }
  return {liquor[answerStart],liquor[answerEnd]};
}
int main(void){
  int n;
  pair<int,int> answer;
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin>>n;
  vector <int> liquor(n);
  for(int i=0;i<n;i++)
    cin>>liquor[i];
  sort(liquor.begin(),liquor.end());
  answer=closeToZero(liquor);
  cout<<answer.first<<" "<<answer.second;
  return 0;
}
