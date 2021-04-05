#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
bool setCompare(set<int> a,set<int> b){
    int temp=b.size();
    set <int> t=b;
    for(auto iter=a.begin();iter!=a.end();++iter)
        t.insert(*iter);
    return temp==t.size();
}
void BackTracking(set<set<int>>&a,vector<vector<string>>& relation,vector<int>&v,int& answer,int n,int cnt,int index=0){
    static bool visit[9]={false};
    if(v.size()==cnt){
        bool insertAble=true;
        set<string> s;
        set<int> temp;
        for(int i=0;i<relation.size();i++){
            string key="";
            for(int j=0;j<v.size();j++) key+=relation[i][v[j]]+"A";
            s.insert(key);
        }
        if(s.size()==relation.size()){
            for(int i:v) temp.insert(i);
            for(auto iter=a.begin();iter!=a.end();++iter){
                if(setCompare(*iter,temp)){
                    insertAble=false;
                    break;
                }
            }
            if(insertAble) {
            a.insert(temp);
            answer=max((int)a.size(),answer);}
        }
        return;
    }
    else{
        for(int i=index;i<n;i++){
            if(!visit[i]){
                visit[i]=true;
                v.push_back(i);
                BackTracking(a,relation,v,answer,n,cnt,i+1);
                v.pop_back();
                visit[i]=false;
            }
        }
    }
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    set<set<int>> a;
    for(int i=1;i<=relation[0].size();i++){
        vector <int> v;
        BackTracking(a,relation,v,answer,relation[0].size(),i);}
    return answer;
}
