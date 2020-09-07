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

const int MAX=10100;
int n,m;
vector<pii> graph[MAX];		
//vector<int> maxcost;			//src에서 각 노드까지 최대 비용. 
int maxcost;
bool visited[MAX];
int src,dst; 				//출발점,도착점 

//가중치 그래프에서 출발지에서 도착지까지의 최장 거리(노드 한번씩만 지나는 한붓그리기로 최장거리) 
void maxcost_dfs(int here,int cost){
	//cout<<here<<" "<<cost<<"\n";
	if(here==dst){
		maxcost=max(maxcost,cost);
		return;
	}
	
	visited[here]=true;
	
	for(int i=0;i<graph[here].size();i++){
		int nxt,nxtcost; nxt=graph[here][i].fs,nxtcost=cost+graph[here][i].sc;
		if(not visited[nxt]) maxcost_dfs(nxt,nxtcost);
	}
	
	visited[here]=false;		//백트래킹 
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,c; cin>>u>>v>>c;
		graph[u].push_back({v,c});		//무향 그래프 
		graph[v].push_back({u,c});		
	}
	
	cin>>src>>dst;
	maxcost_dfs(src,0);
	cout<<maxcost<<"\n";
}		
