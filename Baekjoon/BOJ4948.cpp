#include <iostream>
#include <vector>
#define MAX 123456*2+1

using namespace std;
bool NotPrime[MAX]={false};
vector <int> PrimeNum;
int PrimeCount(int temp){
  int cnt=0;
  for(int i=0;i<PrimeNum.size();i++){
    if(PrimeNum[i]>temp && 2*temp>=PrimeNum[i])
      cnt++;
  }
  return cnt;
}
void PrimeIniter(int n){
NotPrime[0]=1;
NotPrime[1]=1;
  for(int i=2;i*i<n;i++){
    if(NotPrime[i]==false){
      for(int j=2;j*i<n;j++){
        NotPrime[j*i]=true;
      }
    }
  }
  for(int i=2;i<=n;i++){
    if(NotPrime[i]==false)
      PrimeNum.push_back(i);
  }
}
int main(void){
int temp;
  PrimeIniter(MAX);
  do{
    cin>>temp;
    if(temp==0)
      break;
    cout<<PrimeCount(temp)<<"\n";
  }while(true);
  return 0;
}
