#include <iostream>
using namespace std;
enum Direction{EAST=1,WEST=2,NORTH=3,SOUTH=4};
int arr[21][21]={0};//0은 안씀
int command[1001]={0};//0안씀
int dice[7]={0};
int paperCraft[6]={6,3,4,2,5,1};
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
int temp[6]={ paperCraft[0], paperCraft[1], paperCraft[2], paperCraft[3], paperCraft[4], paperCraft[5]};
  switch (direction) {
    case EAST:
    paperCraft[0]=temp[1];
    paperCraft[1]=temp[5];
    paperCraft[2]=temp[0];
    paperCraft[3]=temp[3];
    paperCraft[4]=temp[4];
    paperCraft[5]=temp[2];
    break;
    case WEST:
    paperCraft[0]=temp[2];
    paperCraft[1]=temp[0];
    paperCraft[2]=temp[5];
    paperCraft[3]=temp[3];
    paperCraft[4]=temp[4];
    paperCraft[5]=temp[1];
    break;
    case NORTH:
    paperCraft[0]=temp[3];
    paperCraft[1]=temp[1];
    paperCraft[2]=temp[2];
    paperCraft[3]=temp[5];
    paperCraft[4]=temp[0];
    paperCraft[5]=temp[4];
    break;
    case SOUTH:
    paperCraft[0]=temp[4];
    paperCraft[1]=temp[1];
    paperCraft[2]=temp[2];
    paperCraft[3]=temp[0];
    paperCraft[4]=temp[5];
    paperCraft[5]=temp[3];
    break;
  }
  return    paperCraft[0];
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
