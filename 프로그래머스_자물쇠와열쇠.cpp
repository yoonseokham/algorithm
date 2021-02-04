#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int,int> > moveCordinate(int n){
    vector<pair<int,int> > result;
    for(int i=-n;i<=n;i++){
        for(int j=-n;j<=n;j++)
            result.push_back({i,j});
    }
    return result;
}
void rotated(int arr[][63],int n){
 int brr[63][63]={0};
    for(int i=0;i<3*n;i++){
        for(int j=0;j<3*n;j++){
            brr[j][3*n-1-i]=arr[i][j];
        }
    }
    for(int i=0;i<3*n;i++){
        for(int j=0;j<3*n;j++){
            arr[i][j]=brr[i][j];
        }
    }
}
bool moveKey(int arr[][63],int n, pair<int,int> a,int locked[][63]){
    int index=a.first,jndex=a.second;
    int brr[63][63]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i+n][j+n]==1){
                brr[i+n+index][j+n+jndex]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(!((brr[i+n][j+n]==0&&locked[i+n][j+n]==1)||(brr[i+n][j+n]==1&&locked[i+n][j+n]==0))) return false;
    }
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int keyed[63][63]={0};
    int locked[63][63]={0};
    int n2=key[0].size();
    int n=lock[0].size();
    vector<pair<int,int> > result=moveCordinate(n);
    bool a;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            locked[i+n][j+n]=lock[i][j];
        }
    }
    for(int i=0;i<n2;i++){
        for(int j=0;j<n2;j++){
            keyed[i+n][j+n]=key[i][j];
        }
    }
    for(int i=0;i<4;i++){
        rotated(locked,n);
        for(int j=0;j<result.size();j++){
            a=moveKey(keyed,n,result[j], locked);
            if(a==true) return true;
        }
    }
    return false;
}
