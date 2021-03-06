#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;
int star_length(int target,vector<int>& temp){
    int starlength=0;
    for(int i=0;i<temp.size()-1;i++){
        if((temp[i]==target || temp[i+1]==target) && temp[i]!=temp[i+1]){
            starlength++;
            i++;
        }
    }
    return starlength;
}
int solution(vector<int> a) {
    int Max=0,temp=0,last_temp;
    for(int i=0;i<a.size();i++)
        Max=max(a[i],Max);
    vector <pair<int,int> > cache;
    for(int i=0;i<=Max;i++)
        cache.push_back({0,i});
    
    for(int i=0;i<a.size();i++)
        cache[a[i]].first++;
    
    sort(cache.begin(),cache.end(),greater<pair <int,int > >());
    last_temp=star_length(cache[0].second,a);
    for(int i=1;i<cache.size();i++){
        temp=star_length(cache[i].second,a);
        if(last_temp>=temp)
            break;
        last_temp=temp;
    }
    return last_temp*2;
}
