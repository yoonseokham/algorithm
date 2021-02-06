#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(string expression) {
    char cased[6][3]={{'+','-','*'},
                     {'+','*','-'},
                     {'-','*','+'},
                     {'-','+','*'},
                     {'*','+','-'},
                     {'*','-','+'},};
    vector <string> oper;
    vector <long long> numbers;
    string num="";
    long long Max=-1;
    for(int i=0;i<expression.length();i++){
        if(expression[i]=='+'||expression[i]=='*'||expression[i]=='-'){
            string temp;
            temp.push_back(expression[i]);
            oper.push_back(temp);
            if(num.length()!=0){
                numbers.push_back((long long )stoi(num));
                num="";
            }
        }
        else
            num+=expression[i];
    }
    numbers.push_back((long long)stoi(num));
   for(int i=0;i<6;i++){
        vector <string> tmp_oper=oper;
        vector <long long > tmp_numbers=numbers;
       for(int j=0;j<3;j++){
           for(int l=0;l<tmp_oper.size();l++){
                if(cased[i][j]==tmp_oper[l][0]){
                    if(tmp_oper[l][0]=='+')
                        tmp_numbers[l]=tmp_numbers[l]+tmp_numbers[l+1];
                    else if(tmp_oper[l][0]=='*'){
                        tmp_numbers[l]=tmp_numbers[l]*tmp_numbers[l+1];}
                    else if(tmp_oper[l][0]=='-'){
                        tmp_numbers[l]=tmp_numbers[l]-tmp_numbers[l+1];}
                    tmp_oper.erase(tmp_oper.begin()+l);
                    tmp_numbers.erase(tmp_numbers.begin()+l+1);
                    l--;
               }
           }
       }
       Max=Max>abs(tmp_numbers[0])?Max:abs(tmp_numbers[0]);
   }
    return Max;
}
