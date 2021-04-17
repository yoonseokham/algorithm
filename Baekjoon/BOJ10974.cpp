#include <iostream>
using namespace std;
#define MAX 8
int arr[MAX]={1,2,3,4,5,6,7,8};
void swap(int* a,int* b){
  int temp=*a;
  *a=*b;
  *b=temp;
  return;
}
bool nextPermutation(int *arr,int n){
  int i=n-1,j=n-1;
  while(i>0&&arr[i-1]>arr[i])
    i--;
  if(i<=0) return false;//마지막 순열
  while(arr[i-1]>arr[j])
    j--;
  swap(arr[i-1],arr[j]);
  j=n-1;
  while(i<j){
    swap(arr[i],arr[j]);
    i++,j--;
  }
  return true;
}
int main(void){
int n;
cin>>n;
do{
for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
cout<<"\n";}while(nextPermutation(arr,n));
}
