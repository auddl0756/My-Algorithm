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

//simple segment tree( index tree?)

const int MAX=2e6;
const int mod=1e9+7;
ll tree[MAX];

void build(){
	for(int i=n-1;i>0;i--){
		tree[i]=tree[i<<1]*tree[(i<<1)|1];
		tree[i]%=mod;
	}
}

void update(int idx,int val){
	idx+=n-1;
	tree[idx]=val;
	while(idx>1){
		tree[idx/2]=tree[idx]*tree[idx^1];
		tree[idx/2]%=mod;
		idx>>=1;
	}
}

int query(int l,int r){	//[ㅣ,r)구간의 합 또는 곱을 구해줄 수 있음. 여기선 곱 
	ll ret=1;
	l+=n-1,r+=n-1;
	while(l<r){
		if(l&1){
			ret*=tree[l];
			ret%=mod;
			l+=1;
		}
		if(r&1){
			r-=1;
			ret*=tree[r];
			ret%=mod;
		}
		l>>=1; r>>=1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int Q,n;
	for(int i=0;i<MAX;i++) tree[i]=1;
	
	for(int i=0;i<n;i++) cin>>tree[n+i];		
	
	build();	//build segment tree
	
	for(int i=0;i<Q;i++){
		int a,b,c; cin>>a>>b>>c;
		if(a==1){
			update(b,c);
		}else{
			cout<<(ll)query(b,c+1)<<'\n';
		}
	}
}



