#include <iostream>
#include <vector>
using namespace std;
vector <int> tree[27];
void preorder(int nodeNum=0){
  cout<<char(nodeNum+'A');
  for(int i=0;i<tree[nodeNum].size();i++){
    if(tree[nodeNum][i]!='.'-'A')
      preorder(tree[nodeNum][i]);
  }
}
void inorder(int nodeNum=0){
  if(nodeNum=='.'-'A')
    return;
  inorder(tree[nodeNum][0]);
  cout<<char(nodeNum+'A');
  inorder(tree[nodeNum][1]);
}
void postorder(int nodeNum=0){
  for(int i=0;i<tree[nodeNum].size();i++){
    if(tree[nodeNum][i]!='.'-'A')
      postorder(tree[nodeNum][i]);
  }
  cout<<char(nodeNum+'A');
}
int main(void){

  int n;
  char temp[3];
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<3;j++)
      cin>>temp[j];
      tree[temp[0]-'A'].push_back(temp[1]-'A');
      tree[temp[0]-'A'].push_back(temp[2]-'A');
  }
  preorder();
  cout<<"\n";
  inorder();
  cout<<"\n";
  postorder();
}
