#include <string>
#include <vector>

using namespace std;
vector <int> v;
int solution(vector<vector<int>> board, vector<int> moves) {
  int answer=0,temp=0;
   for(int i=0;i<moves.size();i++){
       for(int j=0;j<board[0].size();j++){
           if(board[j][moves[i]-1]!=0){
               temp=board[j][moves[i]-1];
               board[j][moves[i]-1]=0;
               if(!v.empty()){
                   if(v.back()==temp){
                       v.pop_back();
                        answer+=2;}
                   else
                       v.push_back(temp);
               }
               else
                    v.push_back(temp);
               break;
           }
       }
   }
    return answer;
}
