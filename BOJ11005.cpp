#include <iostream>
#include <string>
#include<bits/stdc++.h> 
using namespace std;
string num_return(int n){
  string answer="";
  if(0<=n&& n<10){
    answer.push_back(n+'0');
    return answer;
  }
  else{
    answer.push_back(n-10+'A');
    return answer;
  }
}
string convert_decimal_into_b(int n,int b){
  string answer="";
  int leftover=0;
  while(n!=0){
      leftover=n%b;
      answer+=num_return(leftover);
      n=n/b;
  }
  return answer;
}
int main(void){
int n,b;
string answer;
cin>>n>>b;
  answer=convert_decimal_into_b(n,b);
  reverse(answer.begin(),answer.end());
  cout<<answer;
  return 0;
}
