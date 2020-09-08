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
#define lb(arr,num) lower_bound(all(arr),num)

#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define msi map<string,int>

typedef long long ll;
using namespace std;
//typedef vector<vector<int> > matrix;
#define pll pair<ll,ll>

const int MAX=11000;
//vector<int> graph[MAX];
int graph[MAX][MAX];
bool visited[MAX];
int n,m;
vector<int> order;

void dfs(int here){
	visited[here]=true;
	
	for(int nxt=1;nxt<=n;nxt++){
		if(graph[here][nxt] && not visited[nxt]) dfs(nxt);
	}	
	order.push_back(here);		//back tracking idea.
	//debug(order);
}

vector<int> dfs_tpsort(){
	order.clear();
	
	for(int i=1;i<=n;i++){
		if(visited[i]) continue;
		dfs(i);
	}
	reverse(order.begin(),order.end());
	
	//check if exists reverse edge(which means graph is not DAG)
	// i<j. if edge from 'j' to 'i' exists, its not DAG.
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(graph[order[j]][order[i]]) return vector<int>();		
		}
	}
	
	return order;		//possible results of topological sort
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		graph[u][v]=true;
		
	}
	
	vector<int> tp_res=dfs_tpsort();
	debug(tp_res);
}		
