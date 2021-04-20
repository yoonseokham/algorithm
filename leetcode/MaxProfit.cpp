int solution(vector<int> &A) {
    int n=(int)A.size();
    int sum=0;
    int result=0;
    vector <int> profit(n,0);
    for(int i=1;i<n;i++) profit[i]=A[i]-A[i-1];
    for(int i=0;i<n;i++){ 
        sum=max(0,sum+profit[i]);
        result=max(result,sum);
    }
    return result;
}
