#include <bits/stdc++.h>

#define pii pair<int,int>
#define pdi pair<double,int>
#define ppi pair<pair<int,int>,int>
#define pipi pair<pair<int,int>,pair<int,int> >
#define fs first
#define sc second

#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta2(a,n) sort(a,a+n);
#define debug(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define debug2(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";

#define all(v) (v).begin(), (v).end()
#define lb(arr,num) lower_bound(all(arr),num)

#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define msi map<string,int>

typedef long long ll;
using namespace std;

//https://www.acmicpc.net/problem/17979
//n이 10000정도 된다 ==> 2차원 만*만 dp 는 메모리 초과로 불가능. 1차원 dp이거나 그리디일 것임. 근데 이건 dp네. 

const int MAX=10100,MAX2=15100;
int n,m;
vector<int> price;
//vector<vector<int> > a;
vector<pii> a[MAX2];

int dp[MAX2];

int solve(int nowtime){
	if(nowtime==MAX2) return 0;
	
	int& ret= dp[nowtime];
	if(ret!=-1) return ret;
	ret=0;
	
	//not pick
	ret=max(ret,solve(nowtime+1));
	
	//pick
	for(int i=0;i<a[nowtime].size();i++){
		ret=max(ret,solve(a[nowtime][i].fs )+ price[a[nowtime][i].sc]* (a[nowtime][i].fs-nowtime));
	}
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	cin>>m>>n;
	price=vector<int>(m+1);
	for(int i=1;i<=m;i++) cin>>price[i];
	
	for(int i=0;i<n;i++){
		int s,e,t; 
		cin>>s>>e>>t;
		//a.push_back({s,e,t});
		a[s].push_back({e,t});
	}
	
	memset(dp,-1,sizeof(dp));
	
	cout<<solve(0)<<'\n';
	
}	
