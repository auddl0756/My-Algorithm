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
//typedef vector<vector<int> > matrix;
#define pll pair<ll,ll>

//const int LEN=110;
//int dp[LEN][LEN][2];	//n(idx),k(인접비트수:11),state
//int Q,n,k; 

const int MAX=4000100;
bool p[MAX];
vector<int> primes;
int dp[MAX];

void eratos(){
	for(int i=2;i<MAX;i++){
		if(p[i]) continue;
		
		primes.push_back(i);		//for debug
		for(int j=i;j<MAX;j+=i) p[j]=true;  
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
	eratos();
//	cout<<primes.size()<<'\n';
//	for(int i=0;i<10;i++) cout<<primes[i]<<" ";
	
	int s=0,e=s;
	ll now=0;
	int ans=0;
	while(primes[s]<=n){
		e=max(e,s);
		if(now<n){
			now+=primes[e];
			e++;
		}else if(now==n){
			ans++; 
			now-=primes[s];
			s++;
		}else if(now >n){	//always true but for meaning
			now-=primes[s];
			s++;
		}
	}
	cout<<ans<<'\n';
}


