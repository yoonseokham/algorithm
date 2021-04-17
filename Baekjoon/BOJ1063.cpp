#include <iostream>
#include <string>
#define KING 2
#define STONE 1
using namespace std;
int board[8][8]={0};
int di[8]={-1,-1,0,1,1,1,0,-1};
int dj[8]={0,1,1,1,0,-1,-1,-1};
int commandInverter(string a){
	string list[8]={"T","RT","R","RB","B","LB","L","LT"};
	for(int i=0;i<8;i++)
	{
		if(a==list[i])
			return i;
	}
	return -1;
}
void location_changer(string a,int &i ,int &j){
	j=a[0]-'A';
	i=8-(a[1]-'0');
}
void indexToString(int i,int j){
	int x=8-i;
	int y=j+'A';
	cout<<char(y)<<x<<endl;
}
bool outDeter(int ki,int kj,int si,int sj,int command){
	ki+=di[command];
	kj+=dj[command];
	if(ki<0||kj<0||ki>7||kj>7)
		return false;
	else if(ki==si&&kj==sj){
		si+=di[command];
		sj+=dj[command];
		if(si<0||sj<0||si>7||sj>7)
			return false;
	}
	return true;
}
void move(int &ki,int &kj,int &si,int &sj,int command){
	ki+=di[command];
	kj+=dj[command];
	if(ki==si&&kj==sj){
		si+=di[command];
	        sj+=dj[command];
	}
}
int main(void){
string kingLocation,stoneLocation,command;
int n,si,sj,ki,kj,binaryCommand;
	cin>>kingLocation>>stoneLocation>>n;
	location_changer(kingLocation,ki,kj);
	location_changer(stoneLocation,si,sj);
	board[ki][kj]=KING;
	board[si][sj]=STONE;
	for(int i=0;i<n;i++){
	cin>>command;
	binaryCommand=commandInverter(command);
	if(outDeter(ki,kj,si,sj,binaryCommand)){
		move(ki,kj,si,sj,binaryCommand);
		}
	}
	indexToString(ki,kj);
	indexToString(si,sj);
	return 0;
}
