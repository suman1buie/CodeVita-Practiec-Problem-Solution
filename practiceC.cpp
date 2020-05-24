#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<pair<int,int>>&coin,int ammount,int n,int *dp,int no){
    if (dp[ammount]!=INT_MIN){
        return dp[ammount];
    }

    int ans = INT_MIN;
    for (int i = 0; i <n; i++){
        if (coin[i].second>0&&ammount-coin[i].first>=0&&no>0){
            coin[i].second-=1;
            int coinNeed = coinChange(coin,ammount-coin[i].first,n,dp,no-1);
            if (coinNeed!=INT_MIN){
                dp[ammount] = max(dp[ammount],coinNeed+1);
            }
            else{
                coin[i].second+=1;
            }
        }
    }
    return dp[ammount];
}

void solver(){
    vector<pair<int,int>>rsval;
    int n;cin>>n;
	int ammount;cin>>ammount;
    int note_100,note_200,note_500,note_1000;
    cin>>note_100>>note_200>>note_500>>note_1000;
    rsval.push_back({1,note_100});
    rsval.push_back({2,note_200});
    rsval.push_back({5,note_500});
    rsval.push_back({10,note_1000});
    ammount/=100;
    int *dp = new int[ammount+1];
    for (int i = 1; i <=ammount; i++){
        dp[i] = INT_MIN;
    }
    dp[0] = 0;

    int no = 4;
    int main_ans = coinChange(rsval,ammount,no,dp,n);
    if(main_ans==INT_MIN)main_ans=0;
    cout<<main_ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	solver();
	return 0;
}