#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;
vector <int> trash;
vector <int> crane;

int minute=0;
bool one_day_work(void){
//  vector<int>::iterator iter=trash.begin();
  int n=trash.size();
  int i=trash.size()-1;
  if(n==0)
    return false;
 vector <int> TempCrane;
 for(int i=0;i<crane.size();i++)
   TempCrane.push_back(crane.at(i));
  while(trash.size()!=0&&TempCrane.size()!=0){
    if(i>=0){
      if(TempCrane.back()>=trash.at(i)){
        trash.erase(trash.begin()+i);
        TempCrane.pop_back();
      }
    i--;
    }
    if(i<0)
      break;
  }
  if(n==trash.size())
    return false;
  else{
    minute++;
    return true;
  }
}
int main(void){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n,m,temp;
  cin>>n;
  for(int i=0;i<n;i++){
      cin>>temp;
      crane.push_back(temp);
  }
  cin>>m;
  for(int i=0;i<m;i++){
      cin>>temp;
      trash.push_back(temp);
  }
  sort(crane.begin(),crane.end());
  sort(trash.begin(),trash.end());
  if(crane[crane.size()-1]<trash[trash.size()-1]){
    cout<<-1;
    return 0;
  }
  while(one_day_work());
    cout<<minute;
  return 0;
}
