#include <iostream>
#include <vector>
#include <set>
using namespace std;
int Next(int i,int k,int plateNum){
  if(i+k>=plateNum) return (i+k)%plateNum;
  return i+k;
}
int eatCounter(vector<int>& dic){
int counter=0;
  for(int i=0;i<dic.size();i++){
    if(dic[i]>0)  counter++;
  }
  return counter;
}
int main(void) {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int plateNum,menuNum,k,cupon,Max=0;
  cin>>plateNum>>menuNum>>k>>cupon;
  vector <int> circule(plateNum,0);
  vector <int> dic(menuNum+1);
  for(int i=0;i<plateNum;i++)
    cin>>circule[i];
  int start=0;
  for(int j=0;j<k;j++){
    dic[circule[Next(start,j,plateNum)]]++;
  }
  for(int i=0;i<plateNum;i++){
    int temp=eatCounter(dic);
    if(dic[cupon]>0) Max=temp>Max?temp:Max;
    else  Max=temp+1>Max?temp+1:Max;
    dic[circule[i]]--;
    dic[circule[Next(i,k,plateNum)]]++;
  }
  cout<<Max;
  return 0;
}
