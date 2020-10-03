#include <iostream>
#include <string>
using namespace std;
bool check_groupWord(bool visit[],string temp){
	for(int i=0;i<temp.length();i++){
		if(visit[temp[i]-'a']==false){
			visit[temp[i]-'a']=true;
		}
		else if(temp[i]==temp[i-1])
			continue;
		else 
			return false;
	
	}
	return true;
}
int main(void){
int num=0,n=0;
string temp;
	cin>>n;
	for(int i=0;i<n;i++){
		bool visit[26]={false};
		cin>>temp;
		if(check_groupWord(visit,temp))
			num++;
	}
	cout<<num;

	return 0;
}
