#include <iostream>
#include <algorithm>
using namespace std;
int a[7]={0};
long long answer(int n){
  int n1[6]={a[1],a[2],a[3],a[4],a[5],a[6]};
  int n2[12]={a[1]+a[2],a[1]+a[3],a[1]+a[4],a[1]+a[5],
              a[2]+a[3],a[2]+a[4],a[2]+a[6],a[3]+a[5],
              a[3]+a[6],a[4]+a[5],a[4]+a[6],a[5]+a[6]};
  int n3[8]={a[1]+a[2]+a[3],a[1]+a[3]+a[5],a[1]+a[4]+a[5],
             a[1]+a[2]+a[4],a[2]+a[4]+a[6],a[2]+a[3]+a[6],
             a[3]+a[5]+a[6],a[4]+a[5]+a[6]};
  sort(n1,n1+6);
  sort(n2,n2+12);
  sort(n3,n3+8);
  long long a1=n1[0],b1=n2[0],c1=n3[0];
   if(n>=2)
    return a1*(n-2)*(n-1)*4+a1*(n-2)*(n-2)+ b1*(n-2)*4 +b1*(n-1)*4+4*c1;
   if(n==1)
    return n1[1]+n1[2]+n1[3]+n1[4]+n1[0];
  return 0;
}
int main(void){
  int n;
  cin>>n;
  for(int i=1;i<7;i++)
    cin>>a[i];
  cout<<answer(n);
  return 0;
}
