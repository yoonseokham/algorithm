#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int,int>> v;
int main(void){
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	int n,temp[2];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp[0]>>temp[1];
		v.push_back({temp[0],temp[1]});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		cout<<v[i].first<<" "<<v[i].second<<"\n";
	}

	return 0;


}
