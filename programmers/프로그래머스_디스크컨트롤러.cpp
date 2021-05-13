#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> point;

struct cmp{
    bool operator()(point a,point b){
        point temp_a={a.second,a.first};
        point temp_b={b.second,b.first};
        return temp_a>temp_b;
        }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0,curTime=0;
    point curJob;
    deque<point> db;
    priority_queue< point,vector<point>,cmp> pq;
    for(int i=0;i<int(jobs.size());i++) db.push_back({jobs[i][0],jobs[i][1]});
    sort(db.begin(),db.end());
    while(!( pq.empty() && db.empty() )){
        while(!db.empty()){
            if(curTime>=db.front().first) {
                pq.push(db.front());
                db.pop_front();
            }
            else break;
        }
        if(pq.empty()) curTime=db.front().first;  
        else{
            curJob=pq.top();
            pq.pop();
            curTime+=curJob.second;
            answer+=curTime-curJob.first;
        }
    }
    return int(answer/int(jobs.size()));
}
