#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int value;
    map<string,int> m;
    vector <pair<int,string>> v;
    map<string,vector<pair<int,int>> > temp;
    
    for(int i=0;i<genres.size();i++){
        if(m.find(genres[i])==m.end()) m[genres[i]]=plays[i];
        else m[genres[i]]+=plays[i];
        temp[genres[i]].push_back({plays[i],-i});
    }
    for(auto iter=m.begin();iter!=m.end();++iter) v.push_back({iter->second,iter->first});
    sort(v.begin(),v.end(),greater<pair<int,string>>());
    for(auto iter=temp.begin();iter!=temp.end();++iter) sort(iter->second.begin(),iter->second.end(),greater<pair<int,int>>());
    for(int i=0;i<v.size();i++){
        for(int j=0;j<min(2,(int)temp[v[i].second].size());j++) answer.push_back(-temp[v[i].second][j].second);
    }
    return answer;
}
