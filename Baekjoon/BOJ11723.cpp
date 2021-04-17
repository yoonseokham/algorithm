#include <set>
#include <iostream>
#include <string>

using namespace std;
set<int> s;
set<int> emptyS;
set <int> preS={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int operate(string temp,int num){

  if(temp=="add") s.insert(num);
  else if(temp=="remove"){
    if(operate("check",num)==1)
      s.erase(s.find(num));
  }
  else if(temp=="check")
    return s.find(num)==s.end()?0:1;
  else if(temp=="toggle"){
    if(operate("check",num)==0)
      s.insert(num);
    else
      operate("remove",num);
    }
  else if(temp=="all"){
    s=preS;
  }
  else
    s.clear();
  return -1;
}
int main(void){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  int num,result;
  string temp;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    if(!(temp=="all"||temp=="empty"))
    cin>>num;
    result=operate(temp,num);
    if(temp=="check")
      cout<<(int)result<<"\n";
  }
  return 0;
}
