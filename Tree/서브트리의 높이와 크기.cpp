#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
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
#define debug_pii(a) for(int i=0;i<a.size();i++) cout<<"("<<a[i].fs<<","<<a[i].sc<<") "; cout<<"\n";

#define all(v) (v).begin(), (v).end()
#define lb(arr,num) lower_bound(all(arr),num)

#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define msi map<string,int>

typedef long long ll;

using namespace std;
 
const int MAX=2e5+10;
const int mod=1e9+7;

vector<int> tree[MAX];
int depth[MAX],sz[MAX],res[MAX];		//res[i] = sz[i]-depth[i] 
bool visited[MAX];

//서브트리의 depth와 size 구하기.
//depth : 이전 depth +1
//size : 현재 size=1 + 서브트리 size구해오라고 호출. 
int dfs(int here){
	visited[here]=true;
	sz[here]=1;
	
	for(int i=0;i<tree[here].size();i++){
		int nxt=tree[here][i];
		if(not visited[nxt]){
			depth[nxt]=depth[here]+1;
			sz[here]+=dfs(nxt);
		}
	}
	//res[here] =sz[here]-depth[here];
	return sz[here];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); 
	
	int n,k; cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int u,v; cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	
	depth[1]=1;
	dfs(1);
	for(int i=1;i<=n;i++) cout<<sz[i]<<" "; cout<<'\n';
	for(int i=1;i<=n;i++) cout<<depth[i]<<" "; cout<<'\n';
	
}



