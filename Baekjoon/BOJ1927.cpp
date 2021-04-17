#include <iostream>
#include <queue>
using namespace std;
priority_queue <int,vector<int>,greater <int> > q;

int main(void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n,temp;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    if(temp==0){
      if(q.empty()){
        temp=0;
      }
      else{
      temp=q.top();
      q.pop();
      }
      cout<<temp<<"\n";
    }
    else if(temp!=0)
        q.push(temp);
  }
  return 0;
}
