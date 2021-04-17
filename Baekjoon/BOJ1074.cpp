#include <iostream>
#include <cmath>

using namespace std;
int cnt=0;
int r,c;
void recursiveCall(int n,int index=0,int jndex=0){
  if(n==2){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(r==i+index&&c==j+jndex) {
        cout<<cnt;
        return;
      }
      cnt++;
      }
    }
    return;
  }
  if(r<index+n/2){
    if(c<jndex+n/2){
      recursiveCall(n/2,index,jndex);
    }
    else{
      cnt+=(n/2)*(n/2);
      recursiveCall(n/2,index,jndex+n/2);
    }
  }
  else{
    if(c<jndex+n/2){
      cnt+=(n/2)*(n/2)*2;
      recursiveCall(n/2,index+n/2,jndex);
    }
    else{
      cnt+=(n/2)*(n/2)*3;
      recursiveCall(n/2,index+n/2,jndex+n/2);
    }
  }
}
int main(void){
  int n,temp;
  cin>>n>>r>>c;
  temp=pow(2,n);
  recursiveCall(temp);
  return 0;
}
