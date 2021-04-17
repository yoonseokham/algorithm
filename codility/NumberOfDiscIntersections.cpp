#include <algorithm>
#include <deque>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int BS(deque<pair<long long,long long>>&v,long long target){
    int start=0;
    int end=v.size()-1;
    int mid;
    int largestIndex=-1;   
    while(start<=end){
        mid=(start+end)/2;
        if(v[mid].first<=target){
            start=mid+1;
            largestIndex=max(largestIndex,mid);
        }
        else if(v[mid].first>target) {
            end=mid-1;
        }
    }
    return largestIndex+1;
}
int solution(vector<int> &A) {
    deque<pair<long long,long long>> v;
    for(int i=0;i<(int)A.size();i++) v.push_back({(long long)((long long)i-(long long)A[i]),(long long)((long long)i+(long long)A[i])});
    sort(v.begin(),v.end());
    long long sum=0;
    pair<long long,long long> temp;
    long long  result=0;
    while(!v.empty()){
        temp=v[0];
        v.pop_front();
        result=BS(v,temp.second);
        if (result>10000000) return -1;
        if (result!=-1)
            sum+=result;
        if(sum>10000000) return -1;
    }
    return (int)sum;
}
