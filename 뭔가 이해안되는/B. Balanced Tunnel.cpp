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

const int MAX=100010;
bool ans[MAX];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
	vector<int> a(n),b(n);
	
	vector<int> prefixmax(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i]; a[i]--;   	//c[a[i]-1]=i;
	}
	for(int i=0;i<n;i++){
		 cin>>b[i]; b[i]--; 
	}

	vector<int> pos(n);
	for(int i=0;i<n;i++) pos[b[i]]=i;
	
	vector<int> c(n);
	for(int i=0;i<n;i++) c[i]=pos[a[i]];
	
	vector<int> prefix_max(n+1,0);
	prefix_max[0]=c[0];
	
	for(int i=1;i<n;i++) prefix_max[i]=max(prefix_max[i-1],c[i]);
	
	int ans=0;
	
	for(int i=1;i<n;i++){
		if(prefix_max[i-1] > c[i]) ans++;
	}
	cout<<ans<<'\n';
}



