#include <iostream>
#define MAX 51
using namespace std;
bool arr[MAX][MAX]={0};
void visiting(int si,int sj,int rows,int cols){
  int dx[4]={-1,0,1,0};
  int dy[4]={0,1,0,-1};
  arr[si][sj]=0;
  int ai,aj;
  for(int i=0;i<4;i++){
    ai=si+dx[i];
    aj=sj+dy[i];
    if(ai>=0&&aj>=0&&ai<rows&&aj<cols){
      if(arr[ai][aj]==true){
      arr[ai][aj]=0;
        visiting(ai,aj,rows,cols);
      }
    }
  }
  return;
}
int connected_component(int rows,int cols){
int sum=0;
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if(arr[i][j]){
        visiting(i,j,rows,cols);
        sum++;
      }
    }
  }
  return sum;
}
int main(void){
  int testcase=0,n;
  cin>>testcase;
  while(testcase--){
    int rows,cols;
    cin>>rows>>cols>>n;
    for(int i=0;i<n;i++){
      int temp[2];
      cin>>temp[0]>>temp[1];
      arr[temp[0]][temp[1]]=true;
    }
    cout<<connected_component(rows,cols)<<"\n";
  }
  return 0;
}
