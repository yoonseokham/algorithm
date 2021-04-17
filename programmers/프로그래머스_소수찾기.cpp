#include <string>
#include <vector>

using namespace std;
int PrimeNum_initer(int n){
    vector <int> Prime;
    bool PrimeNum[1000001]={false}; 
    for(int i=2;i<=n;i++)
        PrimeNum[i]=true;

    for(int i=2;i*i<=n;i++){
        if(PrimeNum[i]){
         for(int j=2;j*i<=n;j++)
            PrimeNum[i*j]=false;
        }
    }
    for(int i=2;i<=n;i++){
        if(PrimeNum[i])
            Prime.push_back(i);
    }
    return Prime.size();
}
int solution(int n) {
    
    int answer = PrimeNum_initer(n);
    return answer;
}
