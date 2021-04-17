#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> cost;
vector<int> parent;
int smallMoney[10001]={0};
int FindParent(int x){
  if(x==parent[x])  return x;
  else return parent[x]=FindParent(parent[x]);
}
void UnionXY(int x,int y){
  int big,small;
  x=FindParent(x);
  y=FindParent(y);
  big=x>y?x:y;
  small=x>y?y:x;
  if(x!=y)
    parent[big]=small;
}
int main(void){
  int numFriend,relation,money,x,y,sum=0;

  cin>>numFriend>>relation>>money;
  parent.assign(numFriend+1,0);
  cost.assign(numFriend+1,0);
  for(int i=1;i<=numFriend;i++){
    cin>>cost[i];
    parent[i]=i;
  }
  for(int i=0;i<relation;i++){
    cin>>x>>y;
    UnionXY(x,y);
  }
  for(int i=1;i<=numFriend;i++){
    int temp=FindParent(i),minMoney=10001;
    for(int j=1;j<=numFriend;j++){
        if(temp==FindParent(j)) minMoney=min(minMoney,cost[j]);
    }
    smallMoney[temp]=minMoney;
  }
  for(int i=1;i<=numFriend;i++) sum+=smallMoney[i];
  if(sum>money) cout<<"Oh no";
  else cout<<sum;
  return 0;
}
