#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;
#define MAX 1003002
bool PrimeNum[MAX]={0};
bool Palindrome(int n){
  char s[10];
 sprintf(s, "%d", n);
 int i=0,j=strlen(s)-1;
  while(i<j){
    if(s[i++]!=s[j--])
      return false;
    }
  return true;
}
void Prime_deter(int n){
  for(int i=2;i<MAX;i++){
    PrimeNum[i]=true;
  }
  for(int i=2;i*i<MAX;i++){
    if(PrimeNum[i])
    for(int j=2;i*j<MAX;j++){
      if(PrimeNum[i*j])
        PrimeNum[i*j]=false;
    }
  }
  for(int i=2;i<MAX;i++){
    if(PrimeNum[i]&&!Palindrome(i))
      PrimeNum[i]=false;
  }
  for(int i=n;i<MAX;i++){
    if(PrimeNum[i]){
      cout<<i;
      return;
    }
  }
}
int main(void){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  cin>>n;
  Prime_deter(n);
  return 0;
}
