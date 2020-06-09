#include <iostream>
using namespace std;
enum Direction{EAST=1,WEST=2,NORTH=3,SOUTH=4};
int arr[21][21]={0};//0은 안씀
int command[1001]={0};//0안씀
int dice[7]={0};
int fourdirection[6]={6,3,4,2,5,1};
bool moveDeter(int direction,int dice_i,int dice_j,int rows,int cols){
  if(direction==EAST){
      if(dice_j==cols)
        return 0;
  }
  else if(direction==WEST){
      if(dice_j==1)
        return 0;
  }
  else if(direction==NORTH){
    if(dice_i==1)
      return 0;
  }
  else if(direction==SOUTH){
    if(dice_i==rows)
      return 0;
  }
  return true;
}
int dice_index_calculate(int direction,int cur_diceIndx){//전개도 업데이트+해당 방향에 대한 값 리턴
int temp[6]={fourdirection[0],fourdirection[1],fourdirection[2],fourdirection[3],fourdirection[4],fourdirection[5]};
  switch (direction) {
    case EAST:
    fourdirection[0]=temp[1];
    fourdirection[1]=temp[5];
    fourdirection[2]=temp[0];
    fourdirection[3]=temp[3];
    fourdirection[4]=temp[4];
    fourdirection[5]=temp[2];
    break;
    case WEST:
    fourdirection[0]=temp[2];
    fourdirection[1]=temp[0];
    fourdirection[2]=temp[5];
    fourdirection[3]=temp[3];
    fourdirection[4]=temp[4];
    fourdirection[5]=temp[1];
    break;
    case NORTH:
    fourdirection[0]=temp[3];
    fourdirection[1]=temp[1];
    fourdirection[2]=temp[2];
    fourdirection[3]=temp[5];
    fourdirection[4]=temp[0];
    fourdirection[5]=temp[4];
    break;
    case SOUTH:
    fourdirection[0]=temp[4];
    fourdirection[1]=temp[1];
    fourdirection[2]=temp[2];
    fourdirection[3]=temp[0];
    fourdirection[4]=temp[5];
    fourdirection[5]=temp[3];
    break;
  }
  return   fourdirection[0];
}
void diceRoller(int direction,int& cur_diceIndx,int& dice_i,int& dice_j,int rows,int cols){
  if(moveDeter(direction, dice_i, dice_j,rows,cols)){
    if(direction==EAST){
      cur_diceIndx=dice_index_calculate(direction,cur_diceIndx);
      dice_j++;
    }
    else if(direction==WEST){
      cur_diceIndx=dice_index_calculate(direction,cur_diceIndx);
      dice_j--;
    }
    else if(direction==NORTH){
      cur_diceIndx=dice_index_calculate(direction,cur_diceIndx);
      dice_i--;
    }
    else if(direction==SOUTH){
      cur_diceIndx=dice_index_calculate(direction,cur_diceIndx);
      dice_i++;
    }
    if(arr[dice_i][dice_j]==0)
        arr[dice_i][dice_j]=dice[cur_diceIndx];
    else if(arr[dice_i][dice_j]!=0){

        dice[cur_diceIndx]=arr[dice_i][dice_j];
        arr[dice_i][dice_j]=0;
      }

 cout<<dice[7-cur_diceIndx]<<'\n';
  }
}
int main(void){
  int rows,cols, dice_i,dice_j,rolls,cur_diceIndx=6;
  cin>>rows>>cols>>dice_i>>dice_j>>rolls;
  for(int i=1;i<=rows;i++){
    for(int j=1;j<=cols;j++)
      cin>>arr[i][j];
  }
  dice_i++,dice_j++;
  for(int i=1;i<=rolls;i++)
    cin>>command[i];
  for(int i=1;i<=rolls;i++)
    diceRoller(command[i],cur_diceIndx,dice_i,dice_j,rows,cols);
  return 0;
}
