#include <iostream>
#include <vector>
using namespace std;
int arr[9][9]={0};
int lenghtOfzero;
vector <pair<int,int> > zero;
bool out=false;
void ableNum_returner(int i_v,vector<int> &v){
  bool visited[10]={0};
  int indx=zero[i_v].first;
  int jndx=zero[i_v].second;
  for(int i=0;i<9;i++){
    visited[arr[indx][i]]=true;
    visited[arr[i][jndx]]=true;
  }
  if(indx<3){
    if(jndx<3){
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          visited[arr[i][j]]=true;
        }
      }
    }
    else if(jndx<6){
      for(int i=0;i<3;i++){
        for(int j=3;j<6;j++){
          visited[arr[i][j]]=true;
        }
      }
    }
    else{
      for(int i=0;i<3;i++){
        for(int j=6;j<9;j++){
          visited[arr[i][j]]=true;
        }
      }
    }
  }
  else if(indx<6){
    if(jndx<3){
      for(int i=3;i<6;i++){
        for(int j=0;j<3;j++){
          visited[arr[i][j]]=true;
        }
      }
    }
    else if(jndx<6){
      for(int i=3;i<6;i++){
        for(int j=3;j<6;j++){
            visited[arr[i][j]]=true;
        }
      }
    }
    else{
      for(int i=3;i<6;i++){
        for(int j=6;j<9;j++){
          visited[arr[i][j]]=true;
        }
      }
    }
  }
  else{
      if(jndx<3){
        for(int i=6;i<9;i++){
          for(int j=0;j<3;j++){
            visited[arr[i][j]]=true;
          }
        }
      }
      else if(jndx<6){
        for(int i=6;i<9;i++){
          for(int j=3;j<6;j++){
            visited[arr[i][j]]=true;
          }
        }
      }
      else{
        for(int i=6;i<9;i++){
          for(int j=6;j<9;j++){
            visited[arr[i][j]]=true;
          }
        }
      }
    }
    for(int k=1;k<10;k++){
      if(!visited[k])
        v.push_back(k);
    }
  }
  void Sudoku(int i=0,int cnt=0){
    if(cnt==lenghtOfzero&&!out){
      for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
          cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
      }
      out=true;
      return;
    }
    else{
      vector<int> v;
      ableNum_returner(i,v);
      for(int j=0;j<v.size();j++){
        arr[zero[i].first][zero[i].second]=v[j];
        Sudoku(i+1,cnt+1);
        arr[zero[i].first][zero[i].second]=0;
      }
    }
  }
int main(void){

  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cin>>arr[i][j];
      if(arr[i][j]==0)
        zero.push_back(make_pair(i,j));
    }
  }
  lenghtOfzero=zero.size();
  Sudoku();
//   for(int i=0;i<lenghtOfzero;i++){
//     ableNum_returner(i);
//   for(int i=0;i<v.size();i++){
//       cout<<v.at(i)<<" ";
//   }
//   cout<<"\n";
//   v.clear();
// }
  return 0;
}
