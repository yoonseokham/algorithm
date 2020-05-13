#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000
#define MAX 1001
using namespace std;
int visit[MAX];
vector <pair <int,int> > v[MAX];
priority_queue < pair <int,int> > q;
int minusI(int a)
{
	return -1*a;
}
int dijkstar(int numOfBus,int numOfCity,int start,int end){
	for(int i=0;i<=numOfCity;i++){
		visit[i]=INF;
	}
	visit[start]=0;
	for(int i=1;i<=numOfCity;i++){
		q.push({minusI(visit[i]),i});
	}
	while(!q.empty()){
		int curTop=q.top().second;
		int curTopCost=minusI(q.top().first);
		q.pop();
		for (int i=0;i<v[curTop].size();i++){
			if(visit[v[curTop].at(i).first]>v[curTop].at(i).second+curTopCost){
				visit[v[curTop].at(i).first]=v[curTop].at(i).second+curTopCost;
				q.push({minusI(visit[v[curTop].at(i).first]),v[curTop].at(i).first});
			}
		}
	}
	return visit[end];
}
int main(void){
	int numOfCity,numOfBus,start,end;
	cin>>numOfCity>>numOfBus;
	for(int i=0;i<numOfBus;i++){
		int temp[3];
		cin>>temp[0]>>temp[1]>>temp[2];
		v[temp[0]].push_back({temp[1],temp[2]});
	}
	cin>>start>>end;
	cout<<dijkstar(numOfBus,numOfCity,start,end);
	return 0;
	}
