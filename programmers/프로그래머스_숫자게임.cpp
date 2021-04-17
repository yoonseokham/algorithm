#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    priority_queue<int> a;
    priority_queue<int> b;
    for(int i=0;i<A.size();i++)
        a.push(A[i]),b.push(B[i]);
    while(!a.empty()){
        if(a.top()<b.top()){
            answer++;
            a.pop();
            b.pop();
        }
        else a.pop();
    }
    return answer;
}
