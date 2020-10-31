#include <string>
#include <vector>
#include <iostream>


using namespace std;
vector <int> v;
bool visit[8]={false};
int correct=0;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int converter(char a){
    switch(a){
        case  'A':
                return 0;
        case  'C':
                return 1;
        case  'F':
                return 2;
        case  'J':
                return 3;
        case  'M':
                return 4;
        case 'N':
                return 5;
        case  'R':
                return 6;
        case  'T':
                return 7;

    }
}
int indexReturn(int a){
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==a)
            return i;
    }
}
bool conditionCheck(int i,vector <string>& data){
    int first=indexReturn(converter(data[i][0]));
    int second=indexReturn(converter(data[i][2]));
    int Operator=data[i][3];
    int difference=data[i][4]-'0';
    if(Operator=='='){
        return abs(first-second)==difference+1?true:false;
    }
    if(Operator=='<'){
        return abs(first-second)<difference+1?true:false;
    }
    if(Operator=='>'){
         return abs(first-second)>difference+1?true:false;
    }
}
void permutation(int n,vector <string>& data){
    if(v.size()==8){
       for(int i=0;i<n;i++)
       {
           if(conditionCheck(i,data)==false)
            return;
       }
        correct++;
    }
    else{
        for(int i=0;i<8;i++){
            if(visit[i]==false){
                v.push_back(i);
                visit[i]=true;
                permutation(n,data);
                visit[i]=false;
                v.pop_back();
            }
        }
    }
}
int solution(int n, vector<string> data) {
    v.clear();
    for(int i=0;i<8;i++)
        visit[i]=false;
    correct=0;
    int answer = 0;
    permutation(n,data);
    return correct;
}
