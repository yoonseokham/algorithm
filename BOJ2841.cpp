#include <iostream>
#include <vector>
using namespace std;
bool fingerOn[7]={false};
int main(void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  vector <int> fingerOnLine[7];
  int n,p,cnt=0,line,pret,lastPret;
  cin>>n>>p;
  for(int i=0;i<n;i++){
    cin>>line>>pret;
    if(!fingerOn[line]){
      fingerOn[line]=true;
      fingerOnLine[line].push_back(pret);
      cnt++;
    }
    else{
      lastPret=fingerOnLine[line].at(fingerOnLine[line].size()-1);
      if(lastPret<pret){
        fingerOnLine[line].push_back(pret);
        cnt++;
      }
      else if(lastPret==pret)
        continue;
      else{
        while(lastPret>pret&&fingerOnLine[line].size()>0){
          fingerOnLine[line].pop_back();
          cnt++;
          if(fingerOnLine[line].size()==0)
            break;
          lastPret=fingerOnLine[line].at(fingerOnLine[line].size()-1);
        }
        if(fingerOnLine[line].size()==0){
          cnt++;
          fingerOnLine[line].push_back(pret);}
        else if(lastPret==pret)
          continue;
        else{
          fingerOnLine[line].push_back(pret);
          cnt++;
        }
      }
    }
  }
  cout<<cnt;
  return 0;
}
