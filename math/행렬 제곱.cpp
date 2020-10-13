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
typedef vector<vector<ll> > matrix;
#define pll pair<ll,ll>

const int mod=1000;

//정사각행렬 행렬곱 
matrix matmul(matrix& a,matrix& b){
	int n=a.size();
	matrix ret=matrix(n,vector<ll>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				ret[i][j]+=a[i][k]*b[k][j];
				ret[i][j]%=mod;
			}
		}
	}
	return ret;
}

string getbinary(ll b){
	string ret="";
	for(int i=0;i<=63;i++){
		//ll num=(1<<i);
		//ll num=(ll)pow(2,i);
		ll num=1ll<<i;					//오버플로우 안나도록 1ll 을 쉬프트 시켜야 함*************** 
		//cout<<num<<" "<<b<<"\n";
		if(num > b) break;
		if(num&b) ret+='1'; 	//ret='1'+ret;
		else ret+='0'; 			//ret='0'+ret;
	}
	return ret;	//거꾸로된 이진수를 리턴 
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,b; cin>>n>>b;
	matrix a(n,vector<ll>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	
//디버그 
//	matrix c=matmul(a);
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<c[i][j]<<" ";
//		}cout<<'\n';
//	}cout<<'\n';
	
	string binary=getbinary(b);		//b의 2진수 표현. 지수를 2진수로 바꾸면 지수를 더하기로 표현가능. 
	//cout<<binary<<"\n";
	
	matrix ans=matrix(n,vector<ll>(n,0));	//정답 초기화: 단위 행렬 
	for(int i=0;i<n;i++){
		ans[i][i]=1;
	}
	
	for(int i=0;i<binary.size();i++){
		if(binary[i]=='0') continue;
		matrix t=a;
		for(int j=0;j<i;j++){
			t=matmul(t,t);
		}
		ans=matmul(ans,t);
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<ans[i][j]<<" ";
		}cout<<'\n';
	}cout<<'\n';
}


