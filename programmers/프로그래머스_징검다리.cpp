#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
#define MAX 200000000
using namespace std;

int sub_array_Max(deque<int>& start_end_stones,int start,int k,map<int,int> &a){
    a[start_end_stones[start-k]]--;
    if(a[start_end_stones[start-k]]==0) a.erase(a.find(start_end_stones[start-k]));
    
    if(a.find(start_end_stones[start])==a.end())  a[start_end_stones[start]]=0;
    a[start_end_stones[start]]++;
 
    return a.rbegin()->first;
}
int solution(vector<int> stones, int k) {
    map<int,int> a;
    deque<int> start_end_stones;
    for(int i=0;i<stones.size();i++)
        start_end_stones.push_back(stones[i]);
    start_end_stones.push_front(MAX);
    start_end_stones.push_back(MAX);
    for(int i=0;i<k;i++){
        if(a.find(start_end_stones[i])==a.end()) 
            a[start_end_stones[i]]=0;
        a[start_end_stones[i]]++;
    }
    int min_jump=MAX;
    for(int i=k;i<start_end_stones.size();i++){
        min_jump=min(sub_array_Max(start_end_stones,i,k,a),min_jump);
    }
    return min_jump;
}
