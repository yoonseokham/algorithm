//BOJ 리모컨 1107번
#include <iostream>
#include <cmath>
#define MAX 12
using namespace std;
bool brokeNumbers[MAX]={0};//broken[10]==1>-고장 broken[11]==+고장
int digitCount(int destinationNum){
  if(destinationNum==0)
    return 1;
  else
    return log10(destinationNum)+1;
}
bool numberNotBroke(int k){//k가 주어졋을떄 그녀석의 자릿수들이 안망가졋으면 true리턴
  int size=digitCount(k);
  if(k==0&&brokeNumbers[0])
    return false;
  for(int i=size;i>0;i--){
    if(brokeNumbers[(int)(k/pow(10,i-1))%10])
      return false;
  }
  return true;
}
int closestNum(int destinationNum){//숫자키로 갈수잇는 넘버중 destinationNum 보다 큰거나 작은거 리턴
int digit[6]={0};
int sum_down=-1,sum_up=-1;
int size=digitCount(destinationNum);
  if(brokeNumbers[11]==false){//+가 안망가졋을때
    for(int i=destinationNum;i>=0;i--){//-가 안망가졋을때
      if(numberNotBroke(i)){
        sum_down=i;
        break;
      }
    }
  }
  if(brokeNumbers[12]==false){//-가 안망가졋을때
    for(int i=destinationNum;i<1000001 ;i++){//-가 안망가졋을때
      if(numberNotBroke(i)){
        sum_up=i;
        break;
      }
    }
  }
  if(destinationNum==100){
    return 0;
  }
  else if(destinationNum<100){
    if(brokeNumbers[10]&&brokeNumbers[11]){//-,+둘다 망가짐
      return digitCount(destinationNum);
    }
    else if(brokeNumbers[10]){//-만 망가짐
      return digitCount(sum_down)-sum_down+destinationNum;
    }
    else if(brokeNumbers[11]){//+만 망가짐
      if(sum_up==-1)
        return 100-destinationNum;
      else
        return min(digitCount(sum_up)+sum_up-destinationNum,100-destinationNum);
    }
    else{
      if(sum_up==-1&&sum_down==-1)
        return 100-destinationNum;
      else if(sum_up==-1)
        return min(100-destinationNum,digitCount(sum_down)-sum_down+destinationNum);
      else if(sum_down==-1)
        return min(100-destinationNum,digitCount(sum_up)+sum_up-destinationNum);
      else
        return  min(100-destinationNum,min(digitCount(sum_down)-sum_down+destinationNum,digitCount(sum_up)+sum_up-destinationNum));
    }
  }
  else{
    if(brokeNumbers[10]&&brokeNumbers[11]){//-,+둘다 망가짐
      return digitCount(destinationNum);
    }
    else if(brokeNumbers[10]){//-만 망가짐
      if(sum_down==-1)
        return destinationNum-100;
      return min(digitCount(sum_down)-sum_down+destinationNum,destinationNum-100);
    }
    else if(brokeNumbers[11]){//+만 망가짐
        return digitCount(sum_up)+sum_up-destinationNum;
    }
    else{
      if(sum_up==-1&&sum_down==-1)
        return destinationNum-100;
      else if(sum_up==-1)
        return min(destinationNum-100,digitCount(sum_down)-sum_down+destinationNum);
      else if(sum_down==-1)
        return min(destinationNum-100,digitCount(sum_up)+sum_up-destinationNum);
      else
        return  min(destinationNum-100,min(digitCount(sum_down)-sum_down+destinationNum,digitCount(sum_up)+sum_up-destinationNum));
    }
  }
}
int  main(void){
  fill(brokeNumbers, brokeNumbers + 12, false);
int destinationNum, BrokenNum=0;
cin>>destinationNum>>BrokenNum;
for(int i=0;i<BrokenNum;i++){
  int temp=0;
  cin>>temp;
  if(temp=='-')
    brokeNumbers[10]=true;
  else if(temp=='+')
    brokeNumbers[11]=true;
  else
    brokeNumbers[temp]=true;
}
  cout<<closestNum(destinationNum);
  return 0;
}
