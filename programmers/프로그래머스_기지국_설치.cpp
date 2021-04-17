#include <iostream>
#include <vector>

using namespace std;

int NumOfStation(int start,int end,int w){
int temp=(end-start+1)/(2*w+1);
    if(start>end)
        return 0;
    return (end-start+1)%(2*w+1)==0? temp:temp+1;
}
int solution(int n, vector<int> s, int w){
    int answer = 0;
    vector <pair<int,int>> Notsafe;
    vector <pair<int,int>> safe;
    for(int i=0;i<s.size();i++){
       Notsafe.push_back({s[i]-w,s[i]+w});
    }
    if(Notsafe[Notsafe.size()-1].second>n)
        Notsafe[Notsafe.size()-1].second=n;
    if(Notsafe[0].first<1)
        Notsafe[0].first=1;
    for(int i=0;i<Notsafe.size();i++){
        if(i==0){
            answer+=NumOfStation(1,Notsafe[0].first-1,w);
        }
        else{
            answer+=NumOfStation(Notsafe[i-1].second+1,Notsafe[i].first-1,w);
        }
    }
    answer+=NumOfStation(Notsafe[Notsafe.size()-1].second+1,n,w);
    return answer;
}
