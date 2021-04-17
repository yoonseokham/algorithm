#include <bits/stdc++.h>
#define MAX 10001
using namespace std;
typedef tuple<int,int,int,int,int>  point;
void preorder(int index,vector <point> node,vector<vector<int>>& answer){
    int LeftChild=get<3>(node[index]),RightChild=get<4>(node[index]);
    answer[0].push_back(get<2>(node[index]));
    if(get<3>(node[index])!=-1) preorder(get<3>(node[index]),node,answer);
    if(get<4>(node[index])!=-1) preorder(get<4>(node[index]),node,answer);
}
void postorder(int index,vector <point> node,vector<vector<int>>& answer){
    int LeftChild=get<3>(node[index]),RightChild=get<4>(node[index]);
    if(get<3>(node[index])!=-1) postorder(get<3>(node[index]),node,answer);
    if(get<4>(node[index])!=-1) postorder(get<4>(node[index]),node,answer);
    answer[1].push_back(get<2>(node[index]));
}
bool cmp(point a,point b){
    point temp_a={-get<1>(a),get<0>(a),get<2>(a),-1,-1};
    point temp_b={-get<1>(b),get<0>(b),get<2>(b),-1,-1};
    return temp_a<temp_b;
}//y좌표 큰순 정렬-> 그담에 y같으면 x좌표 작은순 정렬
void addNode(int parentIndex,int childIndex,vector <point>& node){
    if(get<0>(node[parentIndex]) > get<0>(node[childIndex])){//left
        if(get<3>(node[parentIndex])==-1) get<3>(node[parentIndex])=childIndex;
        else addNode(get<3>(node[parentIndex]),childIndex,node);
    }
    else if(get<0>(node[parentIndex])<get<0>(node[childIndex])){//right
        if(get<4>(node[parentIndex])==-1) get<4>(node[parentIndex])=childIndex;
        else addNode(get<4>(node[parentIndex]),childIndex,node);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    vector<vector<int>> answer={{},{}};
    vector <point> node;  //x좌표,y좌표, 원래 노드 번호, LeftChild,RightChilde
    
    
    for(int i=0;i<nodeinfo.size();i++) node.push_back({nodeinfo[i][0],nodeinfo[i][1],i+1,-1,-1});
    sort(node.begin(),node.end(),cmp);
    
    for(int i=1;i<node.size();i++) addNode(0,i,node);

    preorder(0,node,answer);
    postorder(0,node,answer);
    return answer;
}
