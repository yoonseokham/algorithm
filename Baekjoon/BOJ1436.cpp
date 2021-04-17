#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool continuos666(int n){
  int count=0;
  string num=to_string(n);
  for(int i=0;i<num.length();i++){
    if(count==3) return true;
    if(num[i]=='6') count++;
    else count=0;}
  return (count>=3);
}
int main(void){
  vector <int> v;
  int n;
  cin>>n;
  for(int i=666;i<=10000666;i++){
    if(continuos666(i)) v.push_back(i);
  }
  cout<<v[n-1];
  return 0;
}
