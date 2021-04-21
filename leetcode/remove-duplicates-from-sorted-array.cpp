#include <set>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> a;
        for(int i:nums) a.insert(i);
        nums.clear();
        for(auto iter=a.begin();iter!=a.end();++iter) nums.push_back(*iter);
        return a.size();
    }
};
