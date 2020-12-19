#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//���װ�� ���ϱ� 
//�⺻������ nCr = n-1Cr + n-1Cr-1		

//�Ǵ� nCr = n!/((n-r)! * r!)
// let A=n!, B=	(n-r)! * r!
// then nCr = A*inverse(B)
//using fermat's little theorem : a^(p-1) mod p =1 (p: prime number, a is not multiple of p)
//   B^(p-1) mod p =1
// =>B*B^(p-2) mod p =1
// =>B^(p-2) mod p = inverse(B)
//as a result,{A*inverse(B)}%p ={A*(B^(p-2)%p)}%p
// inverse(B) was fraction. but B^(p-2) is integer now.
//::�յ����� �ٷ� ��, �丣�� �������� �̿��ؼ� �м��� ������ �ٲ��� �� �ִ�. 
// so call it "modular inverse".

const int mod=(int)1e9+7;

ll fastpow(ll x,ll e){	//calc x^e
	if(e==0) return 1ll;
	if(e%2) return (fastpow(x,e-1)*x)%mod;
	else{
		ll half=fastpow(x,e/2)%mod;
		return (half*half)%mod;
	}
}

int main(){
	
	ll n,r; cin>>n>>r;
	
	// A=n! , B=(n-r)! *r!
	ll A=1ll,B=1ll;		
	for(ll i=2;i<=n;i++){
		A*=i; A%=mod;
	}
	
	for(ll i=2;i<=r;i++){
		B*=i; B%=mod;
	}
	
	for(ll i=2;i<=n-r;i++){
		B*=i; B%=mod;
	}
	
	//A,B ���߰� �� = A*inverse(B) %mod = {A*(B^(p-2)%p)}%p
	ll B2=fastpow(B,mod-2);		//���� �ŵ�����. 
	ll ans =(A*B2) %mod;
	cout<<ans<<'\n';
	
}

