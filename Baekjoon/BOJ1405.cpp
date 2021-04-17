#include <iostream>
#include <vector>
using namespace std;
#define p 100
long double probability=0;
bool visit[31][31]={0};
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
long double dp[4]={0};
void crazy_robot(int numOfMove,int indx=14,int jndx=14,long double probabilitis=1){
if(numOfMove==0){
  probability+=probabilitis;
  return;
}
    for(int i=0;i<4;i++){
      if(!visit[indx+di[i]][jndx+dj[i]]){
        visit[indx+di[i]][jndx+dj[i]]=true;
        crazy_robot(numOfMove-1,indx+di[i],jndx+dj[i],probabilitis*dp[i]);
        visit[indx+di[i]][jndx+dj[i]]=false;
      }

    }
}
int main(void){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout.precision(11); cout << fixed;
  int testcase,start,end;
  int numOfMove;
  int n,w,e,s;
  cin>>numOfMove>>e>>w>>s>>n;
  visit[14][14]=true;//시작점
  dp[0]=((long double)n)/p;
  dp[1]=((long double)e)/p;
  dp[2]=((long double)s)/p;
  dp[3]=((long double)w)/p;
  crazy_robot(numOfMove);
  cout<<probability;
  return 0;
}
