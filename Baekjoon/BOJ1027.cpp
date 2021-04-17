#include <iostream>
#include <queue>

#define MAX 51
using namespace std;
priority_queue <long long> q;
long long Building[MAX];
long long ableWatch(long long indx,long long numOfbuildings){//indx에서 볼수있는 빌딩의 수
long long sum=0;
long double NewTanjant;
long double OldTanjant;
 			OldTanjant=(long double)((long double)(Building[indx]-Building[indx-1])/(long double)(1));
			for(long long i=indx-1;i>0;i--){
				if(i==indx-1)
					sum++;
				else{
					NewTanjant=(long double)((long double)(Building[indx]-Building[i])/(long double)(indx-i));
					if(OldTanjant>NewTanjant){
						OldTanjant=NewTanjant;
						sum++;
					}
				}
			}
			OldTanjant=(long double)((long double)(Building[indx]-Building[indx+1])/(long double)(-1));
			for(long long i=indx+1;i<=numOfbuildings;i++){
				if(i==indx+1)
					sum++;
				else{
				NewTanjant=(long double)((long double)(Building[indx]-Building[i])/(long double)(indx-i));
				if(OldTanjant<NewTanjant){
						OldTanjant=NewTanjant;
						sum++;
					}
				}
			}
	return sum;
}
int main(void){
	long long numOfbuildings,height,answer=0;
	cin>>numOfbuildings;
	for(long long i=1;i<=numOfbuildings;i++){
		 cin>>Building[i];
	}
	if(numOfbuildings==2){
		cout<<1;
		return 0;}
	//	cout<<ableWatch(1,numOfbuildings);
	for(long long i=1;i<=numOfbuildings;i++)
		q.push(ableWatch(i,numOfbuildings));
	cout<<q.top();
	return 0;
	}
