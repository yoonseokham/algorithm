#include <iostream>
#include <vector>
int arr[20][20]={0};
bool visit[20][20]={0};
bool visitAlpha[26]={0};
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
using namespace std;
int biggist=0;
void backTrack(int n,int m,int indx=0 ,int jndx=0,int way=1){
    for(int i=0;i<4;i++){
      int tmp_i,tmp_j;
      tmp_i=indx+di[i];
      tmp_j=jndx+dj[i];
      if(!(tmp_i<0||tmp_j<0||tmp_i>=n||tmp_j>=m)){
        if(visitAlpha[arr[tmp_i][tmp_j]-'A']==false&&visit[tmp_i][tmp_j]==false){
          visit[tmp_i][tmp_j]=true;
          visitAlpha[arr[tmp_i][tmp_j]-'A']=true;
          backTrack(n,m,tmp_i,tmp_j,way+1);
          visit[tmp_i][tmp_j]=false;
          visitAlpha[arr[tmp_i][tmp_j]-'A']=false;
        }
      }
    }
  biggist=way>biggist?way:biggist;
}
int  main(void){
int n,m;
cin>>n>>m;
fgetc(stdin);
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
    arr[i][j]=fgetc(stdin);
  }
  fgetc(stdin);
}
  visit[0][0]=true;
  visitAlpha[arr[0][0]-'A']=true;
  backTrack(n,m);
  cout<<biggist;
  return 0;
}
