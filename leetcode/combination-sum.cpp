class Solution {
public:
    void recursiveCall(vector<vector<int>>& answer,vector<int>& candidates, int target,vector<int> temp,int curIndex=0,int curSum=0){
        if(target<curSum) return;
        else if(target==curSum){
            answer.push_back(temp);
        }
        else{
            for(int i=curIndex;i<candidates.size();i++){
                if(curSum+candidates[i]<=target){
                temp.push_back(candidates[i]);
                recursiveCall(answer,candidates,target,temp,i,curSum+candidates[i]);
                temp.pop_back();
                }
            }
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> answer;
        recursiveCall(answer,candidates,target,temp);
        return answer;
    }
};
