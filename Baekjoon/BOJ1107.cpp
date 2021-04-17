#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[10]={0};
bool WrongNumExist(string channel,int n){
  for(int i=0;i<channel.length();i++){
    for(int j=0;j<n;j++){
      if(channel[i]-'0'==arr[j])
        return true;
    }
  }
  return false;
}
int cloestChannel(int channel,int n){
int up=channel;
int down=channel;
  while(down>=0){
    if(WrongNumExist(to_string(down),n))
      down--;
    else
      break;
  }
  while(up<=1000001){
    if(WrongNumExist(to_string(up),n))
      up++;
    else
      break;
  }
  // cout<<down<<" "<<up<<"\n";
  if(down<0){
    return min(abs(channel-100),(int)to_string(up).length()+(int)abs(up-channel));
  }
  else {
    int a=min(to_string(up).length()+abs(up-channel),to_string(down).length()+abs(down-channel));
    return min(a,abs(channel-100));
  }
}
int main(void){
  int channel;
  int n;
  cin>>channel;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>arr[i];
  if(n==10)
    cout<<abs(channel-100);
  else{
    cout<<cloestChannel(channel,n);
  }
  return 0;
}
