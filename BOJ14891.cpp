#include <deque>
#include <iostream>
#include <cstdio>
#include <cmath>
#define CLOCKWISE 1
#define COUNTERCLOCKWISE -1

using namespace std;
deque <int> wheel[4];
int counter(int a){
  if(a==COUNTERCLOCKWISE)
    return CLOCKWISE;
  return COUNTERCLOCKWISE;
}
void initalRotateWheel(int wheelNum,int rotateInfo,int Direaction=0){
int temp;
    int newWheelNum=wheelNum-1;
    if(newWheelNum<=3&&newWheelNum>=0&&(Direaction==0||Direaction==-1)){
      if(wheel[wheelNum][6]!=wheel[newWheelNum][2]){
        initalRotateWheel(newWheelNum,counter(rotateInfo),-1);
      }
    }
    newWheelNum=wheelNum+1;
    if(newWheelNum<=3&&newWheelNum>=0&&(Direaction==0||Direaction==1)){
      if(wheel[wheelNum][2]!=wheel[newWheelNum][6]){
        initalRotateWheel(newWheelNum,counter(rotateInfo),1);
      }
    }
    if(rotateInfo==CLOCKWISE){
        temp=wheel[wheelNum].back();
        wheel[wheelNum].pop_back();
        wheel[wheelNum].push_front(temp);
      }
    else if(rotateInfo==COUNTERCLOCKWISE){
        temp=wheel[wheelNum].front();
        wheel[wheelNum].pop_front();
        wheel[wheelNum].push_back(temp);
      }
  }
int main(void){
  int n,wheelNum,rotateInfo,sum=0,temp;
  for(int i=0;i<4;i++){
    for(int j=0;j<8;j++){
      temp=fgetc(stdin);
      wheel[i].push_back(temp-'0');
    }
    fgetc(stdin);
  }
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>wheelNum>>rotateInfo;
    initalRotateWheel(wheelNum-1,rotateInfo);
  }
  for(int i=0;i<4;i++)
    sum+=(wheel[i][0])*pow(2,i);
  cout<<sum;
  return 0;
}
