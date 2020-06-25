#include <iostream>
#include <deque>
#include <vector>
#define MAX 101
using namespace std;
int arr[MAX][MAX]={0};
vector <pair<int,char> > control;
deque <pair<int,int> > worm;
int counter=0;//게임 시작후 카운터
enum direction{
  north=1,
  east=2,
  south=3,
  west=4
};
void go_ahead(int direct,int& cur_i,int& cur_j){//방향 주어지고 그 방향으로 진행한 인덱스 반환
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
}
void direct_change(int& direct,char way){//방향 주어지고 그 방향으로 진행한 인덱스 반환
  if(way=='L')
    direct--;
  else
    direct++;
  if(direct==0)
    direct=4;
  else if(direct==5)
    direct=1;
}
bool wall_hit(int board_size,int cur_i,int cur_j){//벽 부탁 첫냐? 그럼 트루
  if(cur_i<0)
    return true;
  if(cur_j<0)
    return true;
  if (cur_i>=board_size)
    return true;
  if (cur_j>= board_size)
    return true;
  else
    return false;
}
bool tail_hit(int cur_i,int cur_j){
  for(int i=0;i<worm.size();i++){
    if(worm.at(i).first==cur_i&&worm.at(i).second==cur_j)
      return true;
  }
  return false;
}
int main(void){
   int board_size,apple,i_temp,j_temp,control_count,k=0,directed=2,cur_i=0,cur_j=0;
  cin>>board_size>>apple;
  for(int i=0;i<apple;i++){
    cin>>i_temp>>j_temp;
    arr[i_temp-1][j_temp-1]=1;
  }
   cin>>control_count;
   int temp1;
   char temp2;//컨트롤 정보
  for(int i=0;i<control_count;i++){
    cin>>temp1;
    cin>>temp2;
    control.push_back({temp1,temp2});
  }
    control.push_back({10001,temp2});
  worm.push_front({0,0});
  while(counter<10001){
      cur_i=worm.front().first;
      cur_j=worm.front().second;
      go_ahead(directed,cur_i,cur_j);
        counter++;
      if(tail_hit(cur_i,cur_j)||wall_hit(board_size,cur_i,cur_j)){
        break;
      }
      else{
        worm.push_front({cur_i,cur_j});
        if(arr[cur_i][cur_j]==0) //사과가 아닐경우
          worm.pop_back();
        else
          arr[cur_i][cur_j]=0;
      }
      if(counter==control[k].first){
        direct_change(directed,control[k].second);
        k++;
      }
  }
  cout<<counter;
return 0;
}
