#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int>mp;
bool com(char a,char b){
  return mp[a]<mp[b];
}
void solver(){
  int testcase;cin>>testcase;
  while(testcase--){
    mp.clear();
    string p,s;
    cin>>p>>s;
    int i = 0;
    for(char c:p)mp[c]=i++;
    sort(begin(s),end(s),com);
    cout<<s;
    if(testcase>=1)cout<<endl;
  }
}


int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	solver();
	return 0;
}