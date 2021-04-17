#include <string>
#include <vector>
#include <queue>
using namespace std;
long long solution(int n, vector<int> works) {
    priority_queue <int> pq;
    long long answer = 0;
    int front;
    for(int i=0;i<works.size();i++){
        if(works[i]!=0)
            pq.push(works[i]);
    }
    for(int i=0;i<n;i++){
        front=pq.top();
         pq.pop();
        if(front>0)
             pq.push(front-1);
        if(front==0)
            break;
    }
    while(!pq.empty()){
        front=pq.top();
        answer+=front*front;
        pq.pop();
    }
    return answer;
}
