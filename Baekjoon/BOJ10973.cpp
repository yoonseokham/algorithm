#include <iostream>
using namespace std;
#define MAX 10001
int a[MAX]={0};//순열을 담을 배열
void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
  return;
}
bool PrePermutation(int* a,int n){
  int i=n-1,j;
  while(i>0&&a[i-1]<a[i]) i--;
  if(i<=0) return false;
  j=i;
  while(a[i-1]>a[j]&&j<n) j++;
  swap(a[i-1],a[j-1]);
  j=n-1;
  while(i<j){
    swap(a[i],a[j]);
    i++,j--;
  }
  return true;
}
int main(void){
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  if(!PrePermutation(a,n))
    cout<<-1;
  else{
    for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
    }
}
