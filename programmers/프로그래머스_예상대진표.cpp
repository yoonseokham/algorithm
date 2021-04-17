#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int parentFind(int x,vector <int>& v){
    if(v[x]==x) return x;
    else return v[x]=parentFind(v[x],v);
}
void UnionXY(int x,int y,vector<int> &v){
    x=parentFind(x,v);
    y=parentFind(y,v);
    
    
    int big,small;
    big=x>y?x:y;
    small=x>y?y:x;
   
    v[big]=small;
}
bool xysameParent(int x,int y,vector<int>& v){
    x=parentFind(x,v);
    y=parentFind(y,v);
    return x==y;
}
int solution(int n, int a, int b){
    vector <int> v(n+1);
    v.push_back(0);
    for(int i=0;i<=n;i++) v[i]=i;
    for(int i=0;i<log2(n);i++){
        for(int j=1;j<=n;j+=2*int(pow(2,i))) 
            if(j+int(pow(2,i))<=n) UnionXY(j,j+int(pow(2,i)),v); 
        if(xysameParent(a,b,v)) return i+1;
    }
    return 0;
}
