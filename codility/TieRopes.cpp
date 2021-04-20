int solution(int K, vector<int> &A) {
    int sum=0;
    int answer=0;
    for(int i:A){
        if(sum>=K){
            sum=i;
            answer++;
        }
        else sum+=i;
    }
    if(sum>=K) answer++;
    return answer;
}
