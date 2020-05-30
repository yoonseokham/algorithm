#include <iostream>
#include <string>
#include <map>
using namespace std;
map <string,int> m;
map <string,int>::iterator iter;
int  main(void){
  int n;
  string temp;
  int num;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    if(m.find(temp)!=m.end()){
      m[temp]++;
    }
    else{
      m.insert(make_pair(temp,1));
    }
  }
  int max=m.begin()->second;
  string maxs=m.begin()->first;
  for(iter=m.begin();iter!=m.end();iter++){
    int temp=iter->second;
    if(max<temp){
      max=temp;
      maxs=iter->first;
    }
  }
  cout<<maxs;
  return 0;
}
