#include <set>
#include <iostream>
#include <string>
using namespace std;
void Erase(multiset <int> &doubleQueue,int temp2){
  if(doubleQueue.size()==0)
    return;
  if(temp2==-1) doubleQueue.erase(doubleQueue.begin());
  else doubleQueue.erase(--doubleQueue.end());
}

int main (void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n,temp2,testcase=0;
  string temp1;
    cin>>testcase;
    for(int j=0;j<testcase;j++){
    multiset <int> doubleQueue;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>temp1>>temp2;
      if(temp1=="I") doubleQueue.insert(temp2);
      else  Erase(doubleQueue,temp2);
    }
    if(doubleQueue.size()==0) cout<<"EMPTY"<<"\n";
    else cout<<*(--doubleQueue.end())<<" "<<*doubleQueue.begin()<<"\n";
  }
  return 0;
}
