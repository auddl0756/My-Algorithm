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
#define lbd(arr,num) lower_bound(all(arr),num)

#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define msi map<string,int>

typedef long long ll;
using namespace std;
//typedef vector<vector<ll> > matrix;
#define pll pair<ll,ll>

//map<int,int> mp; 
//int cur[1000010];
int n;
vector<int> a,psum;
int dp[510][510];

int solve(int s,int e){
	if(s==e) return a[s];
	
	int& ret=dp[s][e];
	if(ret!=-1) return ret;
	
	ret=1e9;
	
	for(int k=s;k<=e;k++){
		//ret=max(ret,solve(s,k)+solve(k,e)+(psum[k]-psum[s-1])+(psum[e]-psum[k]));
		//ret=min(ret,solve(k,e) + psum[e]-psum[k]+psum[k]-psum[s]);
		
		ret=min(ret,solve(s,k)+solve(k+1,e)+(psum[e]-psum[s-1]));
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int Q; cin>>Q;
	while(Q--){
		 cin>>n;
		 a=vector<int>(n+1);
		 psum=vector<int>(n+1,0);
		 for(int i=1;i<=n;i++){
		 	 cin>>a[i];
		 	 psum[i]=psum[i-1]+a[i];
		 }
		 
		 memset(dp,-1,sizeof(dp));
		 int ans=1e9;
		 //***********************************************************
		 for(int i=1;i<=n;i++){
		 	ans=min(ans,solve(1,i)+solve(i+1,n));
		 }
		 //***********************************************************
		 cout<<ans<<'\n';

		//cout<<solve(1,n)<<"\n";
	}
}


