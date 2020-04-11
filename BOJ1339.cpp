#include <vector>//1339
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
vector <pair <long long,long long> > alphabet;//등장한 알파벳 전부 넣음
bool arr[26]={0};//a부터 z까지 등장한 알파벳은 true
string s[10];
long long ten[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
void string_total_num(long long n){
  for(long long i=0;i<n;i++){
    for(long long j=s[i].length()-1;j>=0;j--){
      for(long long k=0;k<alphabet.size();k++){
        if(s[i][j]==alphabet.at(k).first){
          alphabet.at(k).second+=ten[s[i].length()-1-j];
        }
      }
    }
  }
}
bool cmp(pair<long long,long long> &a,pair<long long,long long> &b){
  if(a.second>b.second)
    return true;
  else return false;
}
int main(void){
long long n,sum=0;
cin>>n;
for(long long i=0;i<n;i++){
  cin>>s[i];
  for(long long j=0;j<s[i].length();j++){
    arr[s[i][j]-65]=true;
  }
}
for(long long i=0;i<26;i++){
  if(arr[i])
    alphabet.push_back(make_pair(i+65,0));
}
string_total_num(n);
sort(alphabet.begin(),alphabet.end(),cmp);
for(long long k=0,j=9;k<alphabet.size();k++,j--){
    sum+=j*alphabet.at(k).second;//<<"\n";//+=ten[s[i].length-1-j];
}
cout << sum;
  return 0;
}
