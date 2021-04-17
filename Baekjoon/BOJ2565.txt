#include <iostream>

using namespace std;
int max(int a,int b){
return a>b?a:b;
}
int main(void){
int a[501]={0};
int dp[501]={0};
int n,temp1,temp2,max_wire=0;
cin>>n;
for(int i=0;i<n;i++){
	cin>>temp1>>temp2;
	a[temp1]=temp2;
	max_wire=max(temp1,max_wire);
}
dp[1]=1;
for(int i=2;i<=max_wire;i++){
	int max_dp=0;
	
	for(int k=1;k<i;k++){
		if(a[k]!=0&&a[i]>a[k])
			max_dp=max(dp[k],max_dp);
	}
	if(a[i]!=0)
		dp[i]=max_dp+1;
}
temp1=0;
for(int i=1;i<=max_wire;i++){
	temp1=max(temp1,dp[i]);
}
cout<<n-temp1;

return 0;}
