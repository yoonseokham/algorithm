#include <algorithm>
bool cmp(pair<int,int> a,pair<int,int> b){
    pair<int,int> temp_a={a.second,a.first};
    pair<int,int> temp_b={b.second,b.first};
    return temp_a<temp_b;
}
int solution(vector<int> &A, vector<int> &B) {
    vector<pair<int,int>> a;
    int n=(int)A.size();
    for(int i=0;i<n;i++) a.push_back({A[i],B[i]});
    sort(a.begin(),a.end(),cmp);
    // for(int i=0;i<n;i++) cout<<a[i].first<<" "<<a[i].second<<"\n";
    int end=-1,answer=0;
    for(int i=0;i<n;i++){
        if(a[i].first>end){
            end=a[i].second;
            answer++;
        }
    }
    return answer;
}
