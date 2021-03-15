#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s>=n){
            for(int i=0;i<n;i++){
                answer.push_back(int(s/n));
            }
            for(int i=0;i<s%n;i++){
                answer[i]++;
            }
    }
    else
        answer.push_back(-1);
    sort(answer.begin(),answer.end());
    return answer;
}
