#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,numList[11]={0},operatorList[4]={0};
int MaxSum=-1000000001,MinSum=1000000001;
// void recursiveCall(int i=0,int sum=numList[0]){
//   if(i==n-1){
//     MaxSum=max(MaxSum,sum);
//     MinSum=min(MinSum,sum);
//   }
//   else{
//     if(operatorList[0]!=0){
//       operatorList[0]--;
//       recursiveCall(i+1,sum+numList[i+1]);
//       operatorList[0]++;
//     }
//     if(operatorList[1]!=0){
//     operatorList[1]--;
//     recursiveCall(i+1,sum-numList[i+1]);
//     operatorList[1]++;
//     }
//     if(operatorList[2]!=0){
//       operatorList[2]--;
//       recursiveCall(i+1,sum*numList[i+1]);
//       operatorList[2]++;
//     }
//     if(operatorList[3]!=0){
//       operatorList[3]--;
//       recursiveCall(i+1,sum/numList[i+1]);
//       operatorList[3]++;
//     }
//   }
// }
void recursiveCall(int plus,int minus,int mul,int div,int i=0,int sum=numList[0]){
  if(plus==0&&minus==0&&mul==0&&div==0){
    MaxSum=max(MaxSum,sum);
    MinSum=min(MinSum,sum);
    return;
  }
  else if(plus<0||minus<0||mul<0||div<0)
    return;
  recursiveCall(plus-1,minus,mul,div,i+1,sum+numList[i+1]);
  recursiveCall(plus,minus-1,mul,div,i+1,sum-numList[i+1]);
  recursiveCall(plus,minus,mul-1,div,i+1,sum*numList[i+1]);
  recursiveCall(plus,minus,mul,div-1,i+1,sum/numList[i+1]);

}
int main(void){
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>numList[i];
  for(int i=0;i<4;i++)
    cin>>operatorList[i];
  recursiveCall(operatorList[0],operatorList[1],operatorList[2],operatorList[3]);
  cout<<MaxSum<<"\n"<<MinSum;
  return 0;
}
