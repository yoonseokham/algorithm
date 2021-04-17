#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
bool install_wifi_with_space(int c,int space){
  int count=1;
  int install=v[0];
  for(int i=1;i<v.size();i++){
    if(v[i]-install>=space){
      count++;
      install=v[i];
    }
  }
  if(count>=c)
    return true;
  return false;
}
int Search_installWiFi(int c){
  int low=1,high=v[v.size()-1]-v[0],mid,answer=1;
  while(low<=high){
    mid=(low+high)/2;
    if(install_wifi_with_space(c,mid)) {
      low=mid+1;
      answer=mid;
    }
    else high=mid-1;
  }
  return answer;
}
int main(void){
  int n,c,temp;
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin>>n>>c;
  for(int i=0;i<n;i++){
    cin>>temp;
    v.push_back(temp);
  }
  sort(v.begin(),v.end());
  cout<<Search_installWiFi(c);
}
