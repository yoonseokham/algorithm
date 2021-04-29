#include <bits/stdc++.h>
using namespace std;

void StackPush(vector<int> &answer,stack <pair <int,int> > &s,int item,int index){
    
    if(s.empty()) s.push({item,index});
    else if(s.top().first<=item){
	answer[s.top().second]=index;
	s.pop();
        StackPush(answer,s,item,index);
    }
    else s.push({item,index});
}
int main(void){
 int n;
 cin>>n;
 stack<pair<int,int>> s;
 vector<int> v(n,0);
 vector<int> answer(n,-1);
 for(int i=0;i<n;i++) cin>>v[i];
 for(int i=n-1;i>=0;i--){
     StackPush(answer,s,v[i],i);
 }
 for(int i:answer) cout<<i+1<<" "; 
 return 0;
}
