#include <iostream>
#include <vector>
#include <iostream>
#define MAX 101
using namespace std;
void DFS(int n,int start ,int mid,vector <int>  sign[MAX],vector<vector<int> > &arr){
    for(int i=0;i<sign[mid].size();i++){
        if(arr[start][sign[mid][i]]==0){
            arr[start][sign[mid][i]]=1;
            DFS(n,start,sign[mid][i],sign,arr);
        }
    }
}
vector<vector<int> > solution(int n, vector<vector<int> > signs)
{
    vector<vector<int> > arr(n,vector <int>(n,0));
    vector<int> answer[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(signs[i][j]==1){
                answer[i].push_back(j);
            }
        }
    }
    for(int i=0;i<n;i++)
        DFS(n,i,i,answer,arr);

    return arr;
}
