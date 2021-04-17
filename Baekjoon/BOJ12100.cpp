#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;
vector< vector<int> > arr;
vector< vector<int> > temp_arr;
void init_temp(int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      temp_arr[i][j]=arr[i][j];
  }
}
void push_direaction(int direat,int n){
  vector < vector<int> > temp_calcule;
  temp_calcule.assign(n,vector<int>(n,0));
  if (direat==UP){
    for(int j=0;j<n;j++){
      bool combine=false;
      deque <int> tq;
      for(int i=0;i<n;i++){
        if(temp_arr[i][j]!=0){
          if(tq.size()==0)
            tq.push_back(temp_arr[i][j]);
          else if(combine || tq[tq.size()-1]!=temp_arr[i][j])
            tq.push_back(temp_arr[i][j]),combine=false;
          else if(!combine && tq[tq.size()-1]==temp_arr[i][j]){
            tq[tq.size()-1]*=2;
            combine=true;
          }
        }
      }
      for(int k=0;k<tq.size();k++)
        temp_calcule[k][j]=tq[k];
    }
  }
  else if(direat==DOWN){
    for(int j=0;j<n;j++){
      bool combine=false;
      deque <int> tq;
      for(int i=n-1;i>=0;i--){
        if(temp_arr[i][j]!=0){
          if(tq.size()==0)
            tq.push_back(temp_arr[i][j]);
          else if(combine || tq[tq.size()-1]!=temp_arr[i][j])
            tq.push_back(temp_arr[i][j]),combine=false;
          else if(!combine && tq[tq.size()-1]==temp_arr[i][j]){
            tq[tq.size()-1]*=2;
            combine=true;
          }
        }
      }
      for(int k=0;k<tq.size();k++)
        temp_calcule[n-1-k][j]=tq[k];
    }
  }
  else if(direat==LEFT){
    for(int i=0;i<n;i++){
      bool combine=false;
      deque <int> tq;
      for(int j=0;j<n;j++){
        if(temp_arr[i][j]!=0){
          if(tq.size()==0)
            tq.push_back(temp_arr[i][j]);
          else if(combine || tq[tq.size()-1]!=temp_arr[i][j])
            tq.push_back(temp_arr[i][j]),combine=false;
          else if(!combine && tq[tq.size()-1]==temp_arr[i][j]){
            tq[tq.size()-1]*=2;
            combine=true;
          }
        }
      }
      for(int k=0;k<tq.size();k++)
        temp_calcule[i][k]=tq[k];
    }
  }
  else if(direat==RIGHT){
    for(int i=0;i<n;i++){
      bool combine=false;
      deque <int> tq;
      for(int j=n-1;j>=0;j--){
        if(temp_arr[i][j]!=0){
          if(tq.size()==0)
            tq.push_back(temp_arr[i][j]);
          else if(combine || tq[tq.size()-1]!=temp_arr[i][j])
            tq.push_back(temp_arr[i][j]),combine=false;
          else if(!combine && tq[tq.size()-1]==temp_arr[i][j]){
            tq[tq.size()-1]*=2;
            combine=true;
          }
        }
      }
      for(int k=0;k<tq.size();k++){
        temp_calcule[i][n-1-k]=tq[k];
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      temp_arr[i][j]=temp_calcule[i][j];
    }
  }
}
int direactionMaker(int n){
  int Max=0;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      for(int k=0;k<4;k++){
        for(int l=0;l<4;l++){
          for(int m=0;m<4;m++){
            init_temp(n);
            vector<int> command;
            command.push_back(i);
            command.push_back(j);
            command.push_back(k);
            command.push_back(l);
            command.push_back(m);
            for(int z=0;z<5;z++)
              push_direaction(command[z],n);
            for(int x=0;x<n;x++){
              for(int y=0;y<n;y++)
                Max=max(Max,temp_arr[x][y]);
            }
          }
        }
      }
    }
  }
  return Max;
}

int main(void){
  int n,temp;
  cin>>n;
  arr.assign(n,vector<int>(n,0));
  temp_arr.assign(n,vector<int>(n,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>arr[i][j];
      temp_arr[i][j]=arr[i][j];
    }
  }
  cout<<direactionMaker(n);
  return 0;
}
