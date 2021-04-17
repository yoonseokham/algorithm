#include <stack>
void blockPush(stack<int>&block,int input,int &answer){
    if(block.empty()) block.push(input);
    else{
        if(block.top()==input) return;
        else if(block.top()<input) block.push(input);
        else if(block.top()>input){
            block.pop();
            answer++;
            blockPush(block,input,answer);
        }
    }
}
int solution(vector<int> &H) {
    stack<int> block;
    int answer=0;
    for(int i:H) blockPush(block,i,answer);
    return answer+block.size();
}
