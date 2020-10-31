#include <string>
#include <vector>
#include <deque>
using namespace std;
bool isFirst(deque <pair<int,bool>> &printer,int a){
    for(int i=0;i<printer.size();i++){
        if(a<printer[i].first)
            return false;
    }
    return true;
}
int solution(vector<int> priorities, int location) {
    deque <pair<int,bool>> printer;
    int answer=0;
    for(int i=0;i<priorities.size();i++){
        if(location!=i)
            printer.push_back({ priorities[i],false});
        else
            printer.push_back({ priorities[i],true});
    }
    while(!printer.empty()){
        // answer++;
        if(!isFirst(printer,printer[0].first)){
        pair<int,bool> temp=printer[0];
         printer.pop_front();
        printer.push_back(temp);
        }
        else{
            pair<int,bool> temp=printer[0];
            printer.pop_front();
            answer++;
            if(temp.second==true)
                return answer;
        }

    }
}
