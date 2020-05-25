#include <iostream>
#include <vector>
using namespace std;
enum direction{ NORTH=0 ,EAST=1,SOUTH=2,WEST=3};
int arr[51][51]={0};//집 정보를 입력받는데 테두리는 1로 둘러싸기위해 51,51로 선언
bool clean[51][51]={0};//이미 청소된 구역은 1,아니면 0 테두리는 이미 청소되었다고 생각한다.
int cleaned=0;//
int rotater(int d){
	if(d==NORTH)
		return WEST;
	else
		return d-1;
}
pair<int,int> go_ahead(int r ,int c,int d){//방향을 받으면 그 방향대로 진행한 죄표를 리턴.
	if(d==NORTH)
		return {r-1,c};
	else if(d==EAST)
		return {r,c+1};
	else if(d==SOUTH)
		return {r+1,c};
	else
		return {r,c-1};


}
pair<int ,int> go_back(int r,int c,int d){//r,c,d를 입력받으면 뒤로 빠꾸친 좌표 반환 만약 빠구 불가능하면 -1,-1  반환
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
	int i=4;//4방향 검사
	bool not_clean=false;//false면 4방향검사했는데 청소 불가능햇다는것
	while(i--){
		d=rotater(d);//방향돌려주고
		temp=go_ahead(r,c,d);//temp에 일단 그 방향으로 진행한거 저장
		if(clean[temp.first][temp.second]==0&&arr[temp.first][temp.second]==0){//청소 안했고 벽아닌거 발견하면
			robot_algorithm(temp.first,temp.second,d);//temp방향으로 진행
			not_clean=true;//청소했으니 트루로 바꿈
			break;
		}
	}
	if(!not_clean){//만약 청소 못햇음
	temp=go_back(r,c,d);//빠꾸칠 좌표반환
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
			arr[i][j]=1;//테두리를 1로만들기위해 걍 다 1로함
			clean[i][j]=true;//전부 청소햇다함
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];//grid를 제외한 부분 제대로 초기화
			clean[i][j]=false;//grid를 제외한 부분 제대로 초기화
		}
	}
	robot_algorithm(r+1,c+1,d);
	cout<<cleaned;
	return 0;
	}
