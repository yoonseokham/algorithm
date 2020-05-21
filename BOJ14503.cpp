#include <iostream>
#include <vector>
using namespace std;
enum direction{ NORTH=0 ,EAST=1,SOUTH=2,WEST=3};
int arr[51][51]={0};
bool clean[51][51]={0};
int cleaned=0;
int rotater(int d){
	if(d==NORTH)
		return WEST;
	else
		return d-1;
}
pair<int,int> go_ahead(int r ,int c,int d){
	if(d==NORTH)
		return {r-1,c};
	else if(d==EAST)
		return {r,c+1};
	else if(d==SOUTH)
		return {r+1,c};
	else
		return {r,c-1};


}//방향을 받으면 그 방향대로 진행한 죄표를 리턴.
pair<int ,int> go_back(int r,int c,int d){
	if(d==NORTH&&arr[r+1][c]==0)
		return {r+1,c};
	else if(d==EAST&&arr[r][c-1]==0)
		return {r,c-1};
	else if(d==SOUTH&&arr[r-1][c]==0)
		return {r-1,c};
	else if(d==WEST&&arr[r][c+1]==0)
		return {r,c+1};
	return {-1,-1};
}
void robot_algorithm(int r,int c,int d){
	pair <int,int> temp;
	if(clean[r][c]==false){
			cleaned++;
			clean[r][c]=true;
	}
	int i=4;
	bool not_clean=false;
	while(i--){
		d=rotater(d);
		temp=go_ahead(r,c,d);
		if(clean[temp.first][temp.second]==0&&arr[temp.first][temp.second]==0){
			robot_algorithm(temp.first,temp.second,d);
			not_clean=true;
			break;
		}
	}
	if(!not_clean){
	temp=go_back(r,c,d);
	if(temp.first==-1)
		return;
	else{
		robot_algorithm(temp.first,temp.second,d);
	}
}
}
int main(void){
	int n,m,r,c,d;
	cin>>n>>m>>r>>c>>d;
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++){
			arr[i][j]=1;
			clean[i][j]=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
			clean[i][j]=false;
		}
	}
	robot_algorithm(r+1,c+1,d);
	cout<<cleaned;
	return 0;
	}
