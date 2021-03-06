#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
bool segCheck(int i,int j){
    if(i>5 || j>5 ||i<-5||j<-5) return false;
    return true;
}
pair<pair<int,int>,bool> move_robot(map<int,pair<int,int> > m,int direaction,pair<int,int> temp={0,0}){
    int curI=temp.first,curJ=temp.second;
    if(segCheck(curI+m[direaction].first,curJ+m[direaction].second)) return {{curI+m[direaction].first,curJ+m[direaction].second},true};
        return {{curI,curJ},false};   
}
int solution(string dirs) {
    set <pair< pair<int,int> , pair<int,int> > > s;
    map<int,pair<int,int> > m;
    m['U']={-1,0};
    m['D']={1,0};
    m['L']={0,-1};
    m['R']={0,1};
    int answer = 0;
    pair<int,int> start={0,0};
    pair<int,int> end={0,0};
    pair<pair<int,int>,bool> result;
    for(int i=0;i<dirs.size();i++){
        result=move_robot(m,dirs[i],start);  
        end=result.first;
        if(result.second){
            s.insert({{start.first,start.second},{end.first,end.second}});
            s.insert({{end.first,end.second},{start.first,start.second}}); 
        }
        start=end;
    }
    return s.size()/2;
}
