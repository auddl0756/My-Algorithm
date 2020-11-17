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

#define pll pair<ll,ll>
#define pcc pair<char,char>

const int MAX=100;	//10000이하 
const int INF=1e9;

int capacity[MAX][MAX],flow[MAX][MAX],trace[MAX];	//용량,유량,증가경로 추적 및 방문여부(before)
int V,E;
//vector<int> graph[MAX];

void bfs(int src,int sink){
	memset(trace,-1,sizeof(trace));		//-1 means not visited
	queue<int> q;
	trace[src]=src;
	q.push(src);
	
	while(not q.empty() && trace[sink]==-1){
		int here=q.front(); q.pop();

		//인접행렬 방식 
		for(int nxt=0;nxt<=V;nxt++){
			if(capacity[here][nxt] - flow[here][nxt] <=0 || trace[nxt]!=-1) continue;				
			q.push(nxt);
			trace[nxt]=here;
		}
	}		
}


// 포트풀커슨? 에드먼드 카프? 둘이 같은 거 같은데 어쨋든 브루트포스 그리디식으로 최대 유량 찾는 알고리즘. 
//<알고리즘> 
// 1. 계속 증가경로 찾고
//	 a) 찾은 증가경로로 흘려보낼 최소 유량 찾고
//	 b) 최소 유량을 그 증가경로로  흘려보내고 
// 2. 증가경로 못찾았으면 종료.

int maxFlow(int src,int sink){
	int totalFlow=0; 
	memset(flow,0,sizeof(flow));
	 
	while(true){
		//증가경로 찾기 
		bfs(src,sink);	
		
		//증가경로 못 찾음 <==> network에 최대 유량이 형성되었음
		if(trace[sink]==-1) break;		
		int flow_amount =INF;
		
		//증가 경로를 통해 유량을 얼마나 보낼지 정하기 (최소로  조금씩 보내는게 최적이라서 최소값을 찾는다) 
		for(int p=sink;p!=src;p=trace[p]){
			flow_amount = min(flow_amount,capacity[trace[p]][p] - flow[trace[p]][p]);
		}
		
		//증가 경로를 통해 유량을 보내기
		for(int p=sink;p!=src;p=trace[p]){
			flow[trace[p]][p]+=flow_amount;
			flow[p][trace[p]]-=flow_amount;
		}	
		totalFlow+=flow_amount;
		
	}
	
	return totalFlow;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	V='z'-'A';
	cin>>E;
	for(int i=0;i<E;i++){
		char u,v; int c;
		cin>>u>>v>>c;
		capacity[u-'A'][v-'A']+=c;
		capacity[v-'A'][u-'A']+=c;
	}

	cout<<maxFlow(0,'Z'-'A')<<'\n';		
}	





 


