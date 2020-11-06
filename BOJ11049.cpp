#include <vector>
#include <climits>
#include <iostream>

using namespace std;
long long min(long long a,long long b,long long c){
    long long temp =a>b?b:a;
    return temp>c?c:temp;
}
int main(void) {
    int n,temp1,temp2;
    vector<pair<int,int> > v;

    cin >>  n;
    v.push_back({0,0});
    for (int i=0; i<n; i++){
        cin>> temp1;
        cin >> temp2;
        v.push_back({temp1,temp2});
        temp1=temp2;
    }
    long long dp[1001][1001]={0};
    for(int i=1;i<n;i++){
        dp[i][i+1]=v[i].first*v[i].second*v[i+1].second;
    }
    for(int i=2;i<n;i++){
         for(int a=1;a<=n-i;a++){
             dp[a][a+i]=LLONG_MAX;
             for(int k=a;k<a+i;k++)
                dp[a][a+i]=min(dp[a][a+i],dp[a][k]+dp[k+1][a+i]+v[a].first*v[k].second*v[a+i].second,dp[a][a+i]) ;
            
    }
    }
    cout<<dp[1][n];
 
    return 0;
}
