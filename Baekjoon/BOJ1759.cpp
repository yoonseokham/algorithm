#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 15
using namespace std;
vector<char> v;
bool visited[MAX]={0};
char arr[MAX]={0};
bool deter(void){
  int sum_m=0;//모음
  int sum_ja=0;
  for(int i=0;i<v.size();i++){
    if(v[i]=='a'||v[i]=='e'||v[i]=='i'||v[i]=='o'||v[i]=='u')
      sum_m++;
    else
      sum_ja++;
  }
  if(sum_m>=1&&sum_ja>=2)
    return true;
  return false;
}
void password(int cnt,int l,int c,int start=0){
  if(cnt==l&&deter()){
    for(int i=0;i<v.size();i++){
      cout<<v.at(i);
    }
    cout<<"\n";
  }
  else{
    for(int i=start;i<c;i++){
      if(!visited[i]){
        visited[i]=true;
        v.push_back(arr[i]);
        password(cnt+1,l,c,i+1);
        visited[i]=false;
        v.pop_back();
      }
    }
  }
}
int main(void){
  int l,c;
  cin>>l>>c;
  for(int i=0;i<c;i++){
    cin>>arr[i];
  }
  sort(arr,arr+c);
  password(0,l,c);
  return 0;
}
