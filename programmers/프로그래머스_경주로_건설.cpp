#include <string>
#include <vector>
#include <iostream>
#define MAX 1000000000

using namespace std;
bool inline segCheck(int index,int jndex,int n){
    return 0<=index && index<n && 0<=jndex && jndex<n;
}
string DireactionCal(int index,int jndex,int Nindex,int Njndex){
    if(index==Nindex) return "-";
    else return "|";
}
void dfs(vector<vector<int>> &board,vector<vector<int>> &dp,int n,int index,int jndex,string direaction="0"){
    int Nindex,Njndex;
    string NewDireaction="x";
    for(int i=0;i<4;i++){
        Nindex=index+"0121"[i]-'1';
        Njndex=jndex+"1210"[i]-'1';
        if(segCheck(Nindex,Njndex,n)&& board[Nindex][Njndex]==0){
            NewDireaction=DireactionCal(index,jndex,Nindex,Njndex);
            if(direaction==NewDireaction or direaction=="0"){
                if(dp[index][jndex]+100<=dp[Nindex][Njndex]) {
                    dp[Nindex][Njndex]=dp[index][jndex]+100;
                    dfs(board,dp,n,Nindex,Njndex,NewDireaction);
                }
            }
            else{
                if(dp[index][jndex]+600<=dp[Nindex][Njndex]) {
                    dp[Nindex][Njndex]=dp[index][jndex]+600;
                    dfs(board,dp,n,Nindex,Njndex,NewDireaction);
                }
            }
            
        }
    }
}
int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<int>> dp(n,vector<int> (n,MAX));
    dp[0][0]=0;
    dfs(board,dp,n,0,0);
    return dp[n-1][n-1];
}
