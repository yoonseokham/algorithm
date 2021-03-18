#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <set>
#define MAX 200000000
using namespace std;

int solution(vector<int> stones, int k) {
    int min_jump=MAX;
    multiset<int> a;
    deque<int> dq;
    for(int i=0;i<stones.size();i++) dq.push_back(stones[i]);
    dq.push_front(MAX);
    dq.push_back(MAX);
    for(int i=0;i<dq.size();i++){
        if(a.size()<k)  a.insert(dq[i]);
        else{
            min_jump=min(min_jump,*a.rbegin());
            a.erase(a.find(dq[i-k]));
            a.insert(dq[i]);
        }
    }
    return min_jump;
}
