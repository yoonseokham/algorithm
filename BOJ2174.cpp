#include <iostream>
#include <vector>
#define MAX 101
using namespace std;
int arr[MAX][MAX]={0};
int n,m;
pair <pair <int ,int>,int > robot[MAX];
pair <pair <int ,char>,int > command[MAX];
enum direction {
  north=1,
  east=2,
  south=3,
  west=4,
};
char direct_Return(char direct){
  switch (direct) {
    case 'N':
    return 1;
    break;
    case 'E':
    return 2;
    break;
    case 'S':
    return 3;
    break;
    case 'W':
    return 4;
    break;
  }
}
int directionChange(int direct,char command){
  if(command=='F')
    return direct; //호출되면 안됨
  else if(command=='L')
    direct--;
  else if( command=='R')
    direct ++;
  if(direct==0)
    return 4;
  else if(direct==5)
    return 1;
  else
    return direct;
}
int forward_execute(int &cur_i,int &cur_j,int direct){
  int temp=arr[cur_i][cur_j];
  arr[cur_i][cur_j]=0;
  switch (direct) {
    case north:
    cur_i--;
    break;
    case east:
    cur_j++;
    break;
    case south:
    cur_i++;
    break;
    case west:
    cur_j--;
    break;
  }
  return temp;
}
bool game_over(int cur_i,int cur_j,int robot_num,int temp){
  if(cur_i<0||cur_j<0||cur_i>=m||cur_j>=n){
    cout<<"Robot "<<robot_num<<" crashes into the wall";
    return true;
  }
  else if(arr[cur_i][cur_j]!=0){
    cout<<"Robot "<<robot_num<<" crashes into robot "<<arr[cur_i][cur_j];
    return true;
  }
  arr[cur_i][cur_j]=temp;
  return false;
}
int main(void){
  cin>>n>>m;//5,4
  int robot_count=0,command_count=0,x,y,robot_num,iter;
  char direct,commanded;
  cin>>robot_count>>command_count;
  for(int i=1;i<=robot_count;i++){
    cin>>x>>y>>direct;
    robot[i].first.first=m-y;
    robot[i].first.second=x-1;
    robot[i].second=direct_Return(direct);
    arr[m-y][x-1]=i;
  }
  for(int j=0;j<command_count;j++){
    cin>>robot_num>>commanded>>iter;
    command[j].first.first=robot_num;
    command[j].first.second=commanded;
    command[j].second=iter;
  }
  for(int i=0;i<command_count;i++){
    int iterOfCommand=command[i].second;
    char commanded=command[i].first.second;
    int robot_num=command[i].first.first;
    int cur_i=robot[robot_num].first.first,
    cur_j=robot[robot_num].first.second;
    int cur_direction=robot[robot_num].second;
    for(int j=0;j<iterOfCommand;j++){
        if(commanded=='F'){
            int temp=forward_execute(cur_i,cur_j,cur_direction);
            if(game_over(cur_i,cur_j,robot_num,temp))
              return 0;
        }
        else{
              cur_direction=directionChange(cur_direction,commanded);
        }
    }
    robot[robot_num].first.first=cur_i;
    robot[robot_num].first.second=cur_j;
    robot[robot_num].second=cur_direction;
 }
  cout<<"OK";
  return 0;
}
