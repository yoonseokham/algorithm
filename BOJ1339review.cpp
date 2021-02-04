#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
vector <string> v;
map<char,int> countNum;
vector <int> num;


int calMax(){
  int Max=0;
  for(int i=0;i<v.size();i++){
    for(int j=0;j<v[i].size();j++){
      countNum[v[i][j]]+=pow(10,j);
    }
  }
  int x=9;
  for(map<char,int>::iterator it=countNum.begin();it!=countNum.end();++it){
    num.push_back(it->second);
  }
  sort(num.begin(),num.end(),greater<int > ());
  for(int i=0;i<num.size();i++){
    Max+=num[i]*(x--);
  }
  return Max;
}
int main(void){
  int n;
  string temp,reverse;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    reverse="";
    for(int i=temp.length()-1;i>=0;i--) reverse+=temp[i];
    for(int j=0;j<temp.length();j++) countNum.insert(make_pair(temp[j],0));
    v.push_back(reverse);
  }
  cout<<calMax();
}
