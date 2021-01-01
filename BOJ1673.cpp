#include <iostream>
using namespace std;
void ChickenOrder(int coupon,int stamp,int k,int &num_chicken){
  if(coupon==0)
    return;
  num_chicken+=coupon;
  stamp+=coupon;
  coupon=0;
  ChickenOrder(stamp/k,stamp%k,k,num_chicken);
}
int main(void){
  int n,k,num_chicken=0;
  while(cin>>n>>k){
    num_chicken=0;
    ChickenOrder(n,0,k,num_chicken);
    cout<<num_chicken<<"\n";
  }
  return 0;
}
