#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
deque <int> v;
void small_minus(int &total_money){
  int mean,sum=0,size=0;
    while(true){
    mean=total_money/v.size();
    if(v[0]>mean){
      cout<<mean;
      return;
    }
    else{
      sum=0;
      while(v.size()!=0&&mean>=v[0]){
        total_money-=v[0];
        sum=max(sum,v[0]);
        v.pop_front();
      }
      if(v.size()==0){
        cout<<sum;
        return;
        }
      }
    }
}

int main(void){
  int n,total_money,mean,NewMean;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>total_money;
    v.push_back(total_money);
  }
  cin>>total_money;
  sort(v.begin(),v.end());
  small_minus(total_money);
  return 0;
}
