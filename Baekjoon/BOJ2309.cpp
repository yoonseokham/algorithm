#include <iostream>
#include <algorithm>
using namespace std;
void printRealSmall(int *ptr,int fake_i,int fake_j){
  for(int i=0;i<9;i++){
    if(i!=fake_i&&i!=fake_j)
      cout<<ptr[i]<<"\n";
  }
}
void fakeSmallFinder(int * ptr,int sum){
int i=0,j=0;
  for(i=0;i<8;i++){
    for(j=i+1;j<9;j++)
      if(sum-ptr[i]-ptr[j]==100){
        printRealSmall(ptr,i,j);
        return;
      }
  }
}
int main(void){
  int temp[9];
  int sum=0;
  for(int i=0;i<9;i++){
      cin>>temp[i];
      sum+=temp[i];
  }
  sort(temp,temp+9);
  fakeSmallFinder(temp,sum);
  return 0;
}
