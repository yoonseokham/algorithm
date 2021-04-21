#include <string>
#include <stack>
class Solution {
public:
    bool well_formed_parentheses(string a){
        stack<int> s;
        for(int i=0;i<a.length();i++){
            if(s.empty()) s.push(a[i]);
            else if (s.top()=='(' && a[i]==')') s.pop();// continue;
            else s.push(a[i]);
        }
        return s.empty();
    }
    void BackTracking(vector<string> &answer,int n,int curIndex=0,string a=""){
        if(2*n==curIndex) {
            if(well_formed_parentheses(a)) answer.push_back(a);
        }
        else{
            BackTracking(answer,n,curIndex+1,a+'(');
            BackTracking(answer,n,curIndex+1,a+')');
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        BackTracking(answer,n);
        return answer;
    }
};
