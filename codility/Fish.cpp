#include <stack>
void push_fish(stack<pair<int,int>>&liveFish,int curSize,int direaction){
    if(liveFish.empty()) liveFish.push({curSize,direaction});
        else{
            if(liveFish.top().second==0) liveFish.push({curSize,direaction});
            else if(liveFish.top().second==1){
                if(direaction==1) liveFish.push({curSize,direaction});
                else{//B[i]==0이고 front는 1임
                    if(liveFish.top().first>curSize) return;
                    else {
                    liveFish.pop();
                    push_fish(liveFish,curSize,direaction);
                    }
                }
            }
        }
}
int solution(vector<int> &A, vector<int> &B) {
    stack<pair<int,int>> liveFish;
    for(int i=0;i<(int)A.size();i++){
        push_fish(liveFish,A[i],B[i]);
    }
    return liveFish.size();
}
