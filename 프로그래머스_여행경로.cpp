#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
bool TicketAllUse(map<string,int> remain_ticket){
    for(auto iter=remain_ticket.begin();iter!=remain_ticket.end();++iter){
        if(iter->second!=0) return false;
    }
    return true;
}
void DFS(map<string, vector<string>  > &v,map<string,int> &remain_ticket,string start,vector<string> &answer,vector<string>& real_answer){
static bool first_end=false;
    if(TicketAllUse(remain_ticket)&&!first_end){
        first_end=true;
        real_answer=answer;
        return;
    }
    for(int i=0;i<v[start].size();i++){
        if(remain_ticket[start+v[start][i]]!=0){
            remain_ticket[start+v[start][i]]--; 
            answer.push_back(v[start][i]);
            DFS(v,remain_ticket,v[start][i],answer,real_answer);
            answer.pop_back();
            remain_ticket[start+v[start][i]]++; 
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    map<string, vector<string>  > v;
    map<string,int> remain_ticket;
    vector <string> a;
    vector <string> b;
    
    a.push_back("ICN");
    for(int i=0;i<tickets.size();i++){
        v[tickets[i][0]].push_back(tickets[i][1]);
        if(remain_ticket[tickets[i][0]+tickets[i][1]]==1) remain_ticket[tickets[i][0]+tickets[i][1]]++;
        else remain_ticket[tickets[i][0]+tickets[i][1]]=1;
    }
    for(auto iter=v.begin();iter!=v.end();++iter)
        sort(iter->second.begin(),iter->second.end());
    DFS(v,remain_ticket,"ICN",a,b);
    return b;
}
