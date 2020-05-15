#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000
#define MAX 1001
using namespace std;
int root[MAX];
bool visit[MAX];
bool gender[MAX];//male 1 female 0
vector <pair <int,int> > v[MAX];
priority_queue < pair <int,pair<int,int> > > q;
bool visit_all(int numOfSchool){
	for(int i=1;i<=numOfSchool;i++){
		if(visit[i]==false)
			return false;
	}
	return true;
}
bool gender_diffrent(int a,int b){
	if(gender[a]!=gender[b])
		return true;
	else
		return false;
}
int minusI(int a)
{
	return -1*a;
}
void initV(int numOfSchool){
	for(int i=0;i<=numOfSchool;i++){
		root[i]=i;
	}
}
int find(int x){
	if(x==root[x])
		return x;//루트
	else{
		return root[x]=find(root[x]);
	}
}
bool unionIt(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return false;
	else if(x>y)
		root[x]=y;
	else
		root[y]=x;
	return true;
}
int main(void){
	int numOfSchool,numOfLoad,temp[3], w,start,end,sum=0;
	cin>>numOfSchool>>numOfLoad;
	for(int i=1;i<=numOfSchool;i++){
		char memo;
		cin>>memo;
		if(memo=='M')
			gender[i]=1;
		else
			gender[i]=0;
	}
	initV(numOfSchool);
	for(int i=0;i<numOfLoad;i++){
		cin>>temp[0]>>temp[1]>>temp[2];
		if(gender_diffrent(temp[0],temp[1])){

			v[temp[0]].push_back({temp[1],temp[2]});
			v[temp[1]].push_back({temp[0],temp[2]});

			q.push({minusI(temp[2]),{temp[0],temp[1]}});
		}
	}
	while(!q.empty()){
			w=minusI(q.top().first);
			start=q.top().second.first;
			end=q.top().second.second;
			if(unionIt(start,end)){
				sum+=w;
				visit[start]=1;
				visit[end]=1;
			}
			q.pop();
	}
	if(visit_all(numOfSchool))
		cout<<sum;
	else
		cout<<-1;
	return 0;
	}
