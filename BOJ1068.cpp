#include <iostream>
#include <vector>
using namespace std;

vector <int> tree;
vector <bool> Erased;
int LeafCount=0;
void PopNodeTree(int n,int EraseNodeNum){
  if(tree[EraseNodeNum]==-1){
    for(int i=0;i<n;i++)
      Erased[i]=true;
    return;
  }
  Erased[EraseNodeNum]=true;
  for(int i=0;i<n;i++){
    if(tree[i]==EraseNodeNum){
      Erased[i]=true;
      PopNodeTree(n,i);
    }
  }
}
void LeafCounter(int n,int parent=-1){
  bool childFound=false;

  for(int i=0;i<n;i++){
    if(tree[i]==parent&&!Erased[i]){
      childFound=true;
      LeafCounter(n,i);
    }
  }
  if(!childFound&&parent!=-1)
    LeafCount++;
}
int main(void){
  int n,temp;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    tree.push_back(temp);
    Erased.push_back(false);
  }
  cin>>temp;
  PopNodeTree(n,temp);
  LeafCounter(n);
  cout<<LeafCount;
}
