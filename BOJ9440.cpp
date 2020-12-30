#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void zeroLocator(vector <int> &a){
  if(a[0]==0){
    for(int i=1;i<a.size();i++){
      if(a[i]!=0){
          swap(a[0],a[i]);
          return;
      }
    }
  }
  else{
    return;
  }
}
int tenPow(int n){
  if(n==0)
    return 1;
  else
    return 10*tenPow(n-1);
}
int smallistSum(vector<int> &numbers){
vector <int> a[2];
sort(numbers.begin(),numbers.end());
int sum=0,changesum=0;
  for(int i=0;i<numbers.size();i++){
    if(i%2==0)
      a[0].push_back(numbers[i]);
    else
      a[1].push_back(numbers[i]);
  }
  zeroLocator(a[0]);
  zeroLocator(a[1]);
  for(int k=0;k<2;k++){
    for(int i=a[k].size()-1,j=0;i>=0;i--,j++){
      sum+=a[k][i]*tenPow(j);
    }
  }
  swap(a[0][0],a[1][0]);
  for(int k=0;k<2;k++){
    for(int i=a[k].size()-1,j=0;i>=0;i--,j++){
      changesum+=a[k][i]*tenPow(j);
    }
  }
  return min(sum,changesum);
}
int main(void){
  int n=0,temp;
    do{
      vector <int> numbers;
      cin>>n;
      if(n==0)
        return 0;
      for(int i=0;i<n;i++){
        cin>>temp;
        numbers.push_back(temp);
      }
      cout<<smallistSum(numbers)<<"\n";
    }while(n!=0);
  return 0;
}
