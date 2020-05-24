#include<bits/stdc++.h>
using namespace std;

void solver(){
	int n;cin>>n;
	vector<vector<int>> array(n,vector<int>(n));
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin>>array[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <=n; ++j){
			dp[i][j] = min((dp[i-1][j])/2,(dp[i][j-1])/2)+array[i-1][j-1];
		}
	}
	ans = dp[n][n];
	cout<<ans;	
}

int main()
{
	solver();
	return 0;
}