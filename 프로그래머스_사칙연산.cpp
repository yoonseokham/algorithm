#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#define MIN -2100000000
#define MAX  2100000000
using namespace std;

int solution(vector<string> arr)
{   
    int dp[2][101][101]={0};
    int num[101]={0};
    int Operator[100]={0};
    for(int i=0,j=0,k=0;i<arr.size();i++){
        if(i%2==0)
            num[j++]=stoi(arr[i]);
        else
            Operator[k++]=arr[i][0];
    }
    //init code
    for(int i=0;i<arr.size()/2+1;i++){
        for(int j=i;j<arr.size()/2+1;j++){
            if(i==j){
                 dp[0][i][j]=num[i];
                 dp[1][i][j]=num[i];
            }
            else if(i+1==j){
                if(Operator[i]=='+'){
                dp[0][i][j]=num[i]+num[j];
                dp[1][i][j]=num[i]+num[j];}
                else{
                 dp[0][i][j]=num[i]-num[j];
                 dp[1][i][j]=num[i]-num[j];
                }
            }
            else{
                dp[0][i][j]=MIN;
                dp[1][i][j]=MAX;
            }
        }
    }
    //init
    for(int l=0;l<arr.size()/2+1;l++){
    for(int i=0;i<arr.size()/2+1;i++){
        int j=min(i+2+l,(int)arr.size()/2);
            for(int k=i;k<j;k++){
                if(k>arr.size()/2)
                    break;
                if(Operator[k]=='+'){
                    dp[0][i][j]=max(dp[0][i][j],dp[0][i][k]+dp[0][k+1][j]);
                    dp[1][i][j]=min(dp[1][i][j],dp[1][i][k]+dp[1][k+1][j]);
                    }
                else{
                    dp[0][i][j]=max(dp[0][i][j],dp[0][i][k]-dp[1][k+1][j]);
                    dp[1][i][j]=min(dp[1][i][j],dp[1][i][k]-dp[0][k+1][j]);
                }
            }
    }
}
    return dp[0][0][arr.size()/2];
}
