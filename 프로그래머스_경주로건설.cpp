#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool segCheck(int i,int j,int n){
    if(i==0&&j==0) return false;
    if(i>=0&&j>=0&&i<n&&j<n) return true;
    return false;
}
int road_cost(int pre,int i){
    if(pre==-1||i==pre) return 100;
    else return 600;
}
void dfs(vector<int> &answer,vector<vector<int>> &board,int visit[][25],int pre=-1,int curI=0,int curJ=0,int sum=0){
    if(curI==board.size()-1 && curJ==board.size()-1){
        visit[board.size()-1][board.size()-1]=min(visit[board.size()-1][board.size()-1],sum);
        return;
    }
    else{
        for(int i=0;i<4;i++){
            int NewI=curI+"0121"[i]-'1';
            int NewJ=curJ+"1210"[i]-'1';
            if(segCheck(NewI,NewJ,board.size())&&(visit[NewI][NewJ]==0||visit[NewI][NewJ]>=visit[curI][curJ]+road_cost(pre,i))&&board[NewI][NewJ]==0){
                if(visit[NewI][NewJ]!=0)
                    visit[NewI][NewJ]=min(visit[NewI][NewJ],visit[curI][curJ]+road_cost(pre,i));
                else
                    visit[NewI][NewJ]=visit[curI][curJ]+road_cost(pre,i);
                dfs(answer,board,visit,i,NewI,NewJ,sum+road_cost(pre,i));
            }
        }
    }
}
int solution(vector<vector<int>> board) {
    int visit[25][25]={0};
    vector<int> answer;
    int n=board.size();
    dfs(answer,board,visit);
    sort(answer.begin(),answer.end());
    return visit[board.size()-1][board.size()-1];
}
