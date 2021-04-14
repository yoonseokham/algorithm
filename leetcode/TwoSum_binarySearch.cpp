#include <bits/stdc++.h>
class Solution {
public:
    pair<int,int> BSresult(vector<pair<int,int>> &temp,int target){
        int start=0;
        int end=temp.size()-1;
        int mid=0;
        while(start<=end){
            mid=(start+end)/2;
            if(temp[mid].first<target) start=mid+1;
            else if(temp[mid].first>target) end=mid-1;
            else return temp[mid];
        }
        return {-1,-1};
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int> > BS;
        vector<int> answer;
        for(int i=0;i<nums.size();i++) BS.push_back({nums[i],i});
        sort(BS.begin(),BS.end());
        for(int i=0;i<BS.size();i++){
            pair<int,int> cur=BS[i];
            vector<pair<int,int>> temp=BS;
            temp.erase(temp.begin()+i);
            pair<int,int> result=BSresult(temp,target-cur.first);
            if(result.first!=-1){
                answer.push_back(result.second);
                answer.push_back(cur.second);
                sort(answer.begin(),answer.end());
                break;
            }
                
        }
        return answer;
    }
};
