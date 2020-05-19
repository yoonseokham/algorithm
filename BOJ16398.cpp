#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 1001
#define INF 1000000001
using namespace std;

vector <pair <int,int> > v[MAX];
priority_queue < pair<int ,pair< int,int > > > q;
int arr[MAX][MAX]={0};
int parent[MAX]={0};
long long sum=0;
int minusI(int a){
	return -1*a;
}
int find(int x){
	if(parent[x]==x)
		return x;
	else
		return parent[x]=find(parent[x]);
}
bool unionfind(int i,int j){
	i=find(i);
	j=find(j);
	if(i==j)
		return false;
	else if(i>j)
		parent[i]=j;
	else
		parent[j]=i;
	return true;
}
int main(void){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			parent[i]=i;
			for(int j=1;j<=n;j++){
				cin>>arr[i][j];
				if(i==j)
					continue;
				else if(i<j){
					q.push({minusI(arr[i][j]),{i,j}});
					//cout<<arr[i][j];
				}
				v[i].push_back({j,arr[i][j]});
			}
		}
		while(!q.empty()){
			int weight=minusI(q.top().first);
			if(unionfind(q.top().second.first,q.top().second.second)){
				sum+=weight;
			}
			q.pop();
		}
		cout<<sum;
	}
