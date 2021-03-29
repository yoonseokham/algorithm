#include <bits/stdc++.h>

using namespace std;
bool isSame(string a,string b){
    if(a.length()!=b.length()) return false;
    else{
        for(int i=0;i<a.length();i++){
            if(b[i]=='*') continue;
            else if(b[i]!=a[i]) return false;
        }
    }
    return true;
}
void BackTracking(vector<string> user_id,vector<int> &answers,vector<vector<int> >& v,int &answer,int index=0){
    static bool visit[9]={false};
    static set<set<string>> s;
    if(answers.size()>=v.size()){
        set<string> a;
        if(answers.size()==v.size()){
            for(int i=0;i<answers.size();i++) a.insert(user_id[answers[i]]);
            s.insert(a);
            answer=max((int)s.size(),answer);
        }
        return;
    }
    else if(index>=v.size()) return;
    for(int i=0;i<v[index].size();i++){
        if(visit[v[index][i]]==false){
            visit[v[index][i]]=true;
            answers.push_back(v[index][i]);
            BackTracking(user_id,answers,v,answer,index+1);
            visit[v[index][i]]=false;
            answers.pop_back();
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<int> a;
    vector< vector<int> > banned_map(banned_id.size(),vector<int>(0));
    for(int i=0;i<banned_id.size();i++) for(int j=0;j<user_id.size();j++) if(isSame(user_id[j],banned_id[i])) banned_map[i].push_back(j);
    
    BackTracking(user_id,a,banned_map,answer);
    return answer;
}
