#include <bits/stdc++.h>

#define pii pair<int,int>
#define ppi pair<pair<int,int>,int>
#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta2(a,n) sort(a,a+n);

#define p(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define p2(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";

#define all(v) (v).begin(), (v).end()
#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define fi first
#define se second

typedef long long ll;
using namespace std;

ll n,k,A,B;

//ll findmok(ll x){
//	ll mok=x/k;
//	return mok*k;
//}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>k>>A>>B;
	if(n<k){
		cout<<A*(n-1)<<'\n';
		return 0;
	}
	if(k==1){
		cout<<A*(n-1)<<"\n";
		return 0;
	}
	ll ans=0;
	while(n>1){
		if(n<k){
			ans+=A*(n-1);
			//n=1;
			break;
		}else{
			if(n==k){
				ans+=min(A*(n-1),B); //n=1;
				break;
			}else{
				if(n%k==0){		//n -> n/k
					ans+=min(A*(n-n/k),B); n=n/k;
				}else{

					ll res=n%k;
					n-=res;
					ans+=res*A;
				}
			}
		}
	}
	cout<<ans<<'\n';

}
