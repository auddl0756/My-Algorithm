//https://codeforces.com/problemset/problem/1385/D

#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta2(a,n) sort(a,a+n);
#define p(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define p2(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";
typedef long long ll;

int calc(string& s,char c){
	if(s.size()==1){
		return s[0]!=c;
	}
	int mid=s.size()/2;
	string s1 = string(s.begin(),s.begin()+mid);
	int left=calc( s1, c+1);
	left +=s.size()/2 - count(s.begin()+mid,s.end(),c);
	string s2=string(s.begin()+mid,s.end());
	int right=calc(s2,c+1);
	right +=s.size()/2 -count(s.begin(),s.begin()+mid,c);
	return min(left,right);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int Q; cin>>Q;
	while(Q--){
		int n; string s;  cin>>n>>s;
		cout<<calc(s,'a')<<"\n";
	}
}
