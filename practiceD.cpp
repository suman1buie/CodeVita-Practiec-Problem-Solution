#include<bits/stdc++.h>
#define int unsigned int
using namespace std;

void solver(){
	int n;cin>>n;
	int sec;cin>>sec;
	vector<vector<int>>candidates(n,vector<int>(sec+1));
	vector<vector<int>>candidates_cal(n,vector<int>(sec+1,0));

	for(int i = 0;i<n;i++){
		for(int step=0;step<=sec;step++){
			cin>>candidates[i][step];
		}
	}

	for(int i = 0;i<n;i++){
		for(int step=1;step<=sec;step++){
			candidates_cal[i][step] = candidates_cal[i][step-1]+candidates[i][step-1]*candidates[i][sec];
		}
	}

	vector<int>winer(n+1,0);

	for(int j=2;j<sec;j+=2){
		int val = 0,index = 0;
		for(int i=0;i<n;i++){
			if(val<candidates_cal[i][j])val = candidates_cal[i][j],index = i+1;
		}
		winer[index]++;
	}
	int ans = 0,index1 = 0;
	for(int i = 0;i<winer.size();i++){
		if(ans<winer[i])ans = winer[i],index1 = i;
	}
	cout<<index1;
}


int32_t main(){
  	solver();
	return 0;
}