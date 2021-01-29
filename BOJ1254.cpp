#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool pellindrome(string a){
  int start=0,end=a.length()-1;
  while(start<=end){
    if(a[start]!=a[end]){
      return false;
    }
    start++;
    end--;
  }
  return true;
}
string chopper(string temp,int index=0){
string result;
  for(int i=temp.length()-1-index;i>=0;i--){
    result.push_back(temp[i]);
  }
  return result;
}
int pellindromeMaker(string temp){
  vector <int> answer;
  for(int i=0;i<=temp.length();i++){
    string check=temp+chopper(temp,i);
    if(pellindrome(check)){
      answer.push_back(check.length());
    }
  }
  sort(answer.begin(),answer.end());
  return answer[0];
}
int main(void){
  string temp;
  cin>>temp;
  cout<<pellindromeMaker(temp);
  return 0;
}
