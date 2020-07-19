#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;
void TopoloicalSort(int n,int w,vector<int> v[],queue <int> &q,int cost [],int link[],int result[]){
  if(q.empty()){
    for(int i=1;i<=n;i++){
      if(link[i]==0) q.push(i),result[i]=cost[i];
    }
    TopoloicalSort(n,w,v,q,cost,link,result);
  }
  else{
    while(!q.empty()){
      int topIndx=q.front();
      q.pop();
      for(int i=0;i<v[topIndx].size();i++){
        link[v[topIndx].at(i)]--;
        result[v[topIndx].at(i)]=result[v[topIndx].at(i)]>result[topIndx]+cost[v[topIndx].at(i)] ?result[v[topIndx].at(i)]:result[topIndx]+cost[v[topIndx].at(i)];
        if(link[v[topIndx].at(i)]==0)
          q.push(v[topIndx].at(i));
      }
    }
    cout<<result[w]<<"\n";
  }
}
int main(void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int testcase,n,k,w,temp1,temp2;
  cin>>testcase;
  while(testcase--){
    vector <int>  v[MAX];
    queue <int>  q; //시간 , 연결된 노드의 번호
    int cost[MAX]={0};
    int result[MAX]={0};
    int link[MAX]={0};
    cin>>n>>k;
    for(int i=1;i<=n;i++)
      cin>>cost[i];
    for(int i=0;i<k;i++){
    cin>>temp1>>temp2;
    v[temp1].push_back(temp2);
    link[temp2]++;
    }
    cin>>w;
    TopoloicalSort(n,w,v,q,cost,link,result);
  }
  return 0;
}
