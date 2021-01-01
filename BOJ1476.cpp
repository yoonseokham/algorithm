#include <iostream>
using namespace std;
void NextESM(int &i,int &j,int &k){
  i%=15;
  j%=28;
  k%=19;
  i++,j++,k++;
}

int main(void){
  int e,s,m,i=0,j=0,k=0,years=0;
  cin>>e>>s>>m;
  while(true){
    if(i==e && j==s && k==m){
      break;
    }
    years++;
    NextESM(i,j,k);
  }
  cout<<years;
  return 0;
}
