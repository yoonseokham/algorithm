#include <map>
#include <iostream>
#include <string>
using namespace std;
map<string,int> m;
int arr[1000]={0};
int main(void){
  int n,count=0;
  cin>>n;
  string temp;
  for(int i=0;i<n;i++){
    cin>>temp;
    m.insert({temp,i+1});
  }
  for(int i=0;i<n;i++){
    cin>>temp;
    arr[i]=m[temp];
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(arr[i]>arr[j]){
        count++;
        break;}
    }
  }
  cout<<count;
  return 0;
}
