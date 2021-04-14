int solution(vector<int> &A) {
    int top=1;
    if(A.size()>100000) return 0;
    sort(A.begin(),A.end());
    for(int i:A){
            if(top==i) top++;
            else return 0;
    }
    return 1;
}
