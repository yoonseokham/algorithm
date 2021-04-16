#include <queue>
int solution(vector<int> &A) {
    queue<int> oneIndex;
    queue<int> zeroIndex;
    for(int i=0;i<A.size();i++){
        if(A[i]==1) oneIndex.push(i);
        else zeroIndex.push(i);
    }
    int sum=0;
    while(zeroIndex.size()!=0 && oneIndex.size()!=0){
        while(!oneIndex.empty()&&!zeroIndex.empty()&&zeroIndex.front()>oneIndex.front()) oneIndex.pop();
        zeroIndex.pop();
        if(oneIndex.size()>1000000000) return -1;
        sum+=oneIndex.size();
        if(sum>1000000000) return -1;
    }
    return sum;
}
