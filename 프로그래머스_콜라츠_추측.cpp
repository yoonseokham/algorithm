#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int result=0;
void collatzGuess(long long num,int cnt=0){
    if(cnt>500){
        result=-1;
        return;}
    else if(num==1){
        result=cnt;
        return;
    }
    if(num%2==0)
        num/=2;
    else
        num=num*3+1;
    collatzGuess(num,cnt+1);
}
int solution(int num) {
    result=0;
    collatzGuess((long long)num);
    return result;
}
