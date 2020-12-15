#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int first(int i){
    return i%5+1;
}
int second(int i){
    int arr[8]={2, 1, 2, 3, 2, 4, 2, 5};
    return arr[i%8];
}
int third(int i){
    int arr[10]={3,3,1,1,2,2,4,4,5,5};
    return arr[i%10];
}
vector<int> solution(vector<int> answers) {
    vector<int> newA;
    vector<int> newB;
    vector <pair<int,int >> answer;
    int counter[3]={0,0,0};
    for(int i=0;i<answers.size();i++){
        if(answers[i]==first(i))
            counter[0]++;
        if( answers[i]==second(i))
            counter[1]++;
        if(answers[i]==third(i))
            counter[2]++;
    }
    answer.push_back({counter[0],1});
    answer.push_back({counter[1],2});
    answer.push_back({counter[2],3});
    sort(answer.begin(),answer.end(),greater <pair<int,int >> ());
    newA.push_back(answer[0].second);
    for(int i=0;i<3;i++)
        cout<<answer[i].first<<" ";
    for(int i=1;i<3;i++){
        if(answer[i-1].first==answer[i].first)
            newA.push_back(answer[i].second);
        else
            break;
    }
    sort(newA.begin(),newA.end());
    if (newA.size()==0)
        return newB;
    return newA;
}
