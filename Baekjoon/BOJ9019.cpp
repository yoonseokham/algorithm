#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
queue <pair<int,string>> q;
int calculate(int arg,char op){
  int temp;
  if(op=='D'){
    temp=(arg*2)%10000;
    return temp;
  }
  if(op=='S'){
    temp=arg-1;
    if(temp==-1)
      temp=9999;
    return temp;
  }
  if(op=='L'){
    temp=(arg%1000)*10+arg/1000;
    return temp;
  }
  if(op=='R'){
    temp=(arg/10)+(arg%10)*1000;
    return temp;
  }
}
void ClearQueue(queue <pair<int,string> >   &someQueue){
queue <pair<int,string> > empty;
swap(someQueue, empty);
}
void BFS(int start,int end){
// ClearQueue(q);
while(!q.empty())
  q.pop();
bool visit[10000]={false};
visit[start]=true;
q.push({start,""});
int qsize=0;

  while(!q.empty()){
  qsize=q.size();
  for(int i=0;i<qsize;i++){
    pair <int,string> front_element=q.front();
    if(front_element.first==end){
      cout<<front_element.second<<"\n";
      return;
    }
    q.pop();
    string temp2="DSLR";
    for(int j=0;j<4;j++){
      int a=calculate(front_element.first,temp2[j]);
      if(!visit[a]){
          visit[a]=true;
        q.push({a,front_element.second+temp2[j]});

      }
    }
  }
  }
}
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int testcase;
int arg[2];
cin>>testcase;
for(int i=0;i<testcase;i++){
  cin>>arg[0]>>arg[1];
  // if(arg[0]==0)
  //   arg[0]=9999;
  //   if(arg[1]==0)
  //     arg[1]=9999;
  BFS(arg[0],arg[1]);
}
  return 0;
}
