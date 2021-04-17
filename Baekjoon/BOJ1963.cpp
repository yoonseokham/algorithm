#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
vector <int> primeNum;
bool prime[10001]={false};
void init_prime(void){
  prime[0]=false;
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<10001;i++)
    prime[i]=true;
}
void prime_initer(void){
  init_prime();
  for(int i=2;i*i<10001;i++){
    if(prime[i]){
      for(int j=2;i*j<10001;j++)
        prime[i*j]=false;
    }
  }
  for(int i=1000;i<10001;i++)
    if(prime[i])
      primeNum.push_back(i);
}
bool oneDifferent(int a,int b){
  string x=to_string(a);
  string y=to_string(b);
  int cnt=0;
  for(int i=0;i<4;i++){
    if(x[i]==y[i])
      cnt++;
  }
  if(cnt==3)  return true;
  else        return false;
}
int BFS(int start,int end){
  bool visit[10001]={false};
  queue <pair<int ,int > > q;
  pair <int,int> top_e;
  q.push(make_pair(start,0));
  while (!q.empty()) {
    top_e=q.front();
    q.pop();
    visit[top_e.first]=true;
    if(top_e.first==end)
      return top_e.second;
    for(int i=0;i<primeNum.size();i++){
      if(oneDifferent(primeNum[i],top_e.first)&&!visit[primeNum[i]])
          q.push(make_pair(primeNum[i],top_e.second+1));
      }
  }
  return -1;
}
int main(void){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  prime_initer();
  int start,end,testcase,answer;
  cin>>testcase;
  while(testcase--){
  cin>>start>>end;
  answer=BFS(start,end);
  if(answer==-1)
    cout<<"Impossible";
  else
    cout<<answer<<"\n";
  }
  return 0;
}
