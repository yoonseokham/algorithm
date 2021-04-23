#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;
void lowerFunction(string &s){
    for(int i=0;i<s.length();i++)
        if('A'<=s[i] and s[i]<='Z') s[i]+='a'-'A';
}
void InsertAlgorithm(deque<string>& s,int cacheSize,string target,int& miss,int& hit){
    if(cacheSize==0){
        miss++;
        return;
    }
    if(find(s.begin(),s.end(),target)==s.end()) {
        s.push_front(target);
        if(s.size()>cacheSize) s.pop_back();
        miss++;
        }
   else{
        s.erase(find(s.begin(),s.end(),target));
        s.push_front(target);
        hit++;
    }
}
int solution(int cacheSize, vector<string> cities) {
    int hit=0;
    int miss=0;
    int end=0;
    deque<string> s;
    
    for(int i=0;i<cities.size();i++) lowerFunction(cities[i]);
    
    while(s.size()<cacheSize&& end<cities.size()){
        InsertAlgorithm(s,cacheSize,cities[end],miss,hit);
        end++;
    }
    for(int i = end; i< cities.size();i++) InsertAlgorithm(s,cacheSize,cities[i],miss,hit);
    return miss*5+hit;
}
