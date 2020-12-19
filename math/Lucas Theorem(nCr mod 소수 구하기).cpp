#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(),v.end()
#define debug(a) for(int i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<'\n';

//nCr = n-1Cr +n-1Cr-1

//lucas theorem 
// : 자연수 n과 정수 k가 주어졌을 때 이항 계수를 p으로 나눈 나머지를 구하는 프로그램을 작성하시오.(p은 소수)
//=> n,k를 p진법으로 나타내고 p진법으로 표현된 수의 각 자릿수(n,k) %p를 다 곱하면 nCr %p와 같다고 한다.. 
 
ll p;	//mod
ll dp[2100][2100];

ll solve(ll n, ll r){		//precalc binomials.
	if(r>n || n==0) return 0;		
	if(r==0 || n==r) return 1;
	
	ll& ret=dp[n][r];
	if(ret!=-1) return ret;
	ret=0;
	ret=(solve(n-1,r)%p+solve(n-1,r-1)%p)%p;

	return ret;
}

int main(){
	ll n,r; cin>>n>>r>>p;
	vector<ll> coef_n(65,0),coef_r(65,0);
	//ll n0=n,r0=r;
	
	for(int i=0;n!=0;i++){	//낮은 자리부터 담김. 
		coef_n[i]=(n%p);
		n/=p;
	}
	
	for(int i=0;r!=0;i++){
		coef_r[i]=(r%p);
		r/=p;
	}
	
//	debug(coef_n);
//	debug(coef_r);
	
	memset(dp,-1,sizeof(dp));

	ll ans=1;

	for(int i=0;i<65;i++){
		if(coef_n[i]==0 && coef_r[i]==0) break;
		ans*=solve(coef_n[i],coef_r[i]);
//		ans*=bino[coef_n[i]][coef_r[i]];
		ans%=p;
	}
	
	cout<<ans<<'\n';
}



