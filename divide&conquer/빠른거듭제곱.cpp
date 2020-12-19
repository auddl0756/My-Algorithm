#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define debug(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define pii pair<int,int>

typedef long long ll;

using namespace std;

const int MAX=2e5+10;
ll mod;

ll solve(ll a,ll b){
	if(b==0) return 1ll;

	if(b%2){		//지수가 홀수 
		return (solve(a,b-1)%mod)*a;		//재귀적으로 들어가서 mod먼저 안 하면 오버플로우 발생. 
	}else{			//지수가 짝수 
		return (solve(a,b/2)%mod)*(solve(a,b/2)%mod);
	}
}

//이렇게 해야함. 위에 처럼하면 b%2==0일 때, solve(),solve() 2번이나 호출되서 느린거 같음. 
ll fastpow(ll x,ll e){	//calc x^e
	if(e==0) return 1ll;
	if(e%2) return (fastpow(x,e-1)*x)%mod;
	else{
		ll half=fastpow(x,e/2)%mod;
		return (half*half)%mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//calc a^b %mod
	//지수를 반씩 나눠서 분할정복.
	
	ll a,b; cin>>a>>b>>mod;
	
	cout<<solve(a,b)%mod<<"\n";

}




