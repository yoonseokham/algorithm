#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[30]={0};
bool deter(string skill,string skill_trees) {
    int size=skill.size();
    for(int i=0;i<30;i++)
        arr[i]=100;
    for(int j=0;j<size;j++){
        for(int i=0;i<skill_trees.size();i++){
            if(skill[j]==skill_trees[i]){
                arr[j]=i;
                if(j>0){
                    if(arr[j]<arr[j-1])
                        return false;
                }
                break;
            }
        }
    }
    return true;
}
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int size=skill.size();
    for(int i=0;i<skill_trees.size();i++){
        if(deter(skill,skill_trees[i]))
            answer++;
    }
    return answer;
}
