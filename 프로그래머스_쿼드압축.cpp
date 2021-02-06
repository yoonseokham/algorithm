#include <string>
#include <vector>

using namespace std;
int Zero=0;
int One=0;
bool OnlyOneOrZero(vector<vector<int>>& arr,int n,int Index=0,int Jndex=0){
   int temp[2]={0,0};
    for(int i=Index;i<Index+n;i++){
        for(int j=Jndex;j<Jndex+n;j++)
            temp[arr[i][j]]++;
    }
    if(temp[0]==n*n){
        Zero++;
        return true;
    }
    else if(temp[1]==n*n){
        One++;
        return true;
    }
    return false;
}
void RecursiveCounter(vector<vector<int>>& arr,int n,int Index=0,int Jndex=0){  
    if(OnlyOneOrZero(arr,n,Index,Jndex)){
        return;
    }
    else{
        RecursiveCounter(arr,n/2,Index,Jndex);
        RecursiveCounter(arr,n/2,Index+n/2,Jndex);
        RecursiveCounter(arr,n/2,Index,Jndex+n/2);
        RecursiveCounter(arr,n/2,Index+n/2,Jndex+n/2);      
    }
}
vector<int> solution(vector<vector<int>> arr) {
    Zero=0;
    One=0;
    vector <int> a;
    RecursiveCounter(arr,arr.size());
    a.push_back(Zero);
    a.push_back(One);
    return a;
}
