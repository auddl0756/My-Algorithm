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
vector<int> mincost;			//src에서 각 노드까지 최대 비용. 
bool visited[MAX];
int trace[MAX]; 		//추적? 

//가중치 그래프에서 출발지에서 각 노드까지의 최단 거리. ==이게 다익스트라구나.. 
void mincost_bfs(int src){		//==dijkstra algorithm ==priority bfs
	priority_queue<pii,vector<pii>,greater<pii> > pq; pq.push({src,0});		//use min heap. 
	mincost=vector<int>(n,1e9);			//각 노드까지 거리를  무한대로 초기화. 
	mincost[src]=0;						
	
	while(not pq.empty()){
		int here=pq.top().fs,cost=pq.top().sc; pq.pop();
		
		if(mincost[here] < cost) continue;			//갱신할 비용이 현재 비용보다 크면 그건 고려할 필요도 없다. 
		
		for(int i=0;i<graph[here].size();i++){
			int nxt=graph[here][i].fs,nxtcost=cost+graph[here][i].sc;
			if(nxtcost < mincost[nxt]){
				mincost[nxt]=nxtcost;
				pq.push({nxt,nxtcost});
				trace[nxt]=here;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,c; cin>>u>>v>>c;
		graph[u].push_back({v,c});
		graph[v].push_back({u,c});
	}
	int src,dst; 				//출발점,도착점 
	cin>>src>>dst;
	mincost_bfs(src);
	
	cout<<"mincost from src to nodes\n";
	for(int i=1;i<=n;i++) cout<<mincost[i]<<" "; cout<<"\n";
	
	cout<<"trace?\n";
	for(int i=1;i<=n;i++) cout<<trace[i]<<" "; cout<<"\n";
}		
