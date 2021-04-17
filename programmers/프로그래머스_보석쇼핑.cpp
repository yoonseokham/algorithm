#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;

bool all_have(set<string>& gems_valid,map<string,int>& gems_count){ return gems_valid.size()==gems_count.size();}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<tuple<int,int,int>> a;
    set<string> gems_valid;
    map<string,int> gems_count;
    int start=0,end=0;
    for(int i=0;i<gems.size();i++) gems_valid.insert(gems[i]);
    gems_count[gems[start]]=1;
    while(true){
        if(!all_have(gems_valid,gems_count)){
            end++;
            if(end==gems.size()) break;
            if(gems_count.find(gems[end])==gems_count.end()) gems_count[gems[end]]=0;
            gems_count[gems[end]]++;
        }
        else{
            a.push_back({end-start,start,end});
            gems_count[gems[start]]--;
            if(gems_count[gems[start]]<=0) gems_count.erase(gems[start]);
            start++;
        }
    }
    sort(a.begin(),a.end());
    answer.push_back(get<1>(a[0])+1);
    answer.push_back(get<2>(a[0])+1);
    return answer;
}
