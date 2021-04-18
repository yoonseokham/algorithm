#include <map>
int solution(vector<int> &A) {
    map<int,int> m;
    map<int,int> index;

    int n=(int)A.size();
    if(n==0) return -1;
    for(int i=0;i<n;i++){
        index[A[i]]=i;
        if(m.find(A[i])==m.end()) m[A[i]]=1;
        else m[A[i]]++;
    }
    for(auto iter=m.begin();iter!=m.end();++iter) if(iter->second > n/2) return index[iter->first];
    return -1;
}
