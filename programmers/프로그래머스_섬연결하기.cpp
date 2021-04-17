#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int find(int x,int* parent){
    if(parent[x]==x)
        return x;
    else
        return parent[x]=find(parent[x],parent);
}
void unionXY(int x,int y,int cost,int* parent,int& sum){
    x=find(x,parent);
    y=find(y,parent);
    if(x==y)
        return;
    else if(x>y)
        parent[x]=y;
    else
        parent[y]=x;
    sum+=cost;
    return;
}
bool AllConnectDeter(int* parent,int n){
    for(int i=0;i<n-1;i++){
        if(find(i,parent)!=find(i+1,parent))
            return false;
    }
    return true;
}
int solution(int n, vector<vector<int>> cost) {
    int parent[101],answer=0;
    vector < pair< int, pair<int,int> > > edgeInfo;
    int sum=0;
    for(int i=0;i<=n;i++)
        parent[i]=i;
    for(int i=0;i<cost.size();i++){
        edgeInfo.push_back({cost[i][2],{cost[i][0],cost[i][1]}});
    }
    sort(edgeInfo.begin(),edgeInfo.end());
    int i=0;
    while(!AllConnectDeter(parent,n)){
        unionXY(edgeInfo[i].second.first,edgeInfo[i].second.second,edgeInfo[i].first,parent,sum);
        i++;
    }
    return sum;
}
