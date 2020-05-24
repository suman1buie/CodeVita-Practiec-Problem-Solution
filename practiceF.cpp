#include<bits/stdc++.h>
using namespace std;

void solution(){
	int n;cin>>n;
	string s;
	cin>>s;
	int q;cin>>q;
	vector<int>chmap(n);
	vector<int>map(26,0);
	for(unsigned int i = 0;i<s.length();i++){
		chmap[i] = map[s[i]-'a'];
		map[s[i]-'a']++;
	}
	while(q--){
		int ip;cin>>ip;
		cout<<chmap[ip-1];
		if(q>=0)cout<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
	solution();
	return 0;
}