#include <iostream>
#include <vector>
#define ERASED 51
using namespace std;

vector <int> tree;
int LeafCount=0;
void PopNodeTree(int n,int EraseNodeNum){
  tree[EraseNodeNum]=ERASED;
  for(int i=0;i<n;i++){
    if(tree[i]==EraseNodeNum)
      PopNodeTree(n,i);
  }
}
void LeafCounter(int n,int parent=-1){
  bool childFound=false;
  for(int i=0;i<n;i++){
    if(tree[i]==parent){
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
  }
  cin>>temp;
  PopNodeTree(n,temp);
  LeafCounter(n);
  cout<<LeafCount;
}
