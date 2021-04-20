#include <algorithm>
int solution(vector<int> &A) {
    int n=(int)A.size();
    if(n==0) return 0;
    int sum=0;
    int result=0;
    int curIndex=0;
    int endIndex=0;
    int answerStartIndex=0;
    int answerEndIndex=0;
    vector <int> profit(n,0);
    for(int i=1;i<n;i++) profit[i]=A[i]-A[i-1];
    for(int i=0;i<n;i++){ 
        if(sum+profit[i]>=0){
            sum+=profit[i];
            endIndex=i;
            if(result<sum){
                answerStartIndex=curIndex;
                answerEndIndex=endIndex;
                result=sum;
                }
        }
        else{
            sum=0;
            curIndex=i;
            endIndex=i;
        }
    }
    return A[answerEndIndex]-A[answerStartIndex];
}
