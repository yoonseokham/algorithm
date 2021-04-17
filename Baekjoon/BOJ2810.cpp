#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int cupHolder(string s){
  int Scnt=0,Lcnt=0;
  for(int i=0;i<s.length();i++){
    if(s[i]=='S') Scnt++;
    else if(s[i]=='L') Lcnt++;
  }

  return Scnt+Lcnt/2+1;
}
int main(void){
  int n;
  string s;
  cin>>n>>s;
  cout<<min(cupHolder(s),n);
  return 0;
}
