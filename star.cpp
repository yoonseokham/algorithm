#include <iostream>
using namespace std;

int main(void){
int n=11;
cin>>n;
int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cnt++;
			if(i<n/2&&i<=j&&j<n-i){
				if(cnt%2==0) cout<<"+";
				else cout<<"*";
			}
			else if(i>=n/2&&n-i-1<=j&&j<=i){
				
				if(cnt%2==0) cout<<"+";
				else cout<<"*";
			}
			else cout<<"-";
	}
	cout<<"\n";
}
return 0;
}
