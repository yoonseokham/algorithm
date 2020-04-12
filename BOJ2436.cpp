#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector <pair <long long,long long> > v;
bool coprime_deter(long long a,long long b){
long long minium=a>b?b:a;
  for(long long i=2;i<=minium;i++){
    if(a%i==0&&b%i==0)
      return false;
  }
  return true;
}
bool cmp(pair <long long,long long>& a, pair <long long,long long> & b){
  if(a.first+a.second<b.first+b.second)
    return true;
  else
    return false;
}
int main(void){
long long Gcd,Lcm,temp;
cin>>Gcd>>Lcm;
if(Gcd==Lcm){
  cout<<Gcd<<" "<<Lcm;
  return 0;
}
temp=Lcm/Gcd;
long long i=1,j=temp;
while(i<=temp/i){
  if(temp%i==0&&coprime_deter(i,temp/i)){
    if(i<=(long long)sqrt(temp)&&temp/i>=(long long)sqrt(temp)){
      v.push_back(make_pair(i,temp/i));
    }
  }
  i++;
}
sort(v.begin(),v.end(),cmp);
if(Gcd*v.at(0).first<=Gcd*v.at(0).second)
  cout<<Gcd*v.at(0).first<<" "<<Gcd*v.at(0).second;
else
  cout<<Gcd*v.at(0).second<<" "<<Gcd*v.at(0).first;
  return 0;
}
