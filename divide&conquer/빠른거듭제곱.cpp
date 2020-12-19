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

	if(b%2){		//������ Ȧ�� 
		return (solve(a,b-1)%mod)*a;		//��������� ���� mod���� �� �ϸ� �����÷ο� �߻�. 
	}else{			//������ ¦�� 
		return (solve(a,b/2)%mod)*(solve(a,b/2)%mod);
	}
}

//�̷��� �ؾ���. ���� ó���ϸ� b%2==0�� ��, solve(),solve() 2���̳� ȣ��Ǽ� ������ ����. 
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
	//������ �ݾ� ������ ��������.
	
	ll a,b; cin>>a>>b>>mod;
	
	cout<<solve(a,b)%mod<<"\n";

}




