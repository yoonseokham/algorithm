#include <iostream>
#include <map>
#include<string>
using namespace std;

map <string,int> tree;
int main(void){
  string temp;
  int total=0;
  while(getline(cin,temp)){
    if(tree.find(temp)==tree.end()){
      tree[temp]=1;
      total++;}
    else{
      tree[temp]++;
      total++;}
  }
  cout << fixed;
  cout.precision(4);
  for (auto it=tree.begin();it!=tree.end();it++)
    cout<<it->first<<" "<<((double)(it->second)/total)*100.0<<"\n";
  return 0;
}
