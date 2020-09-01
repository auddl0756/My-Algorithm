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

// https://www.acmicpc.net/problem/9466
// 인접행렬법은 이렇게 쓰는 것이다.

const int MAX=110000;
bool bad[MAX];
bool visited[MAX];
//vector<int> graph[MAX];		//인접 리스트 
int graph[MAX];					//*********인접 행렬*********** 
int cnt;


void init(){
	memset(visited,false,sizeof(visited));
	memset(bad,false,sizeof(bad));
	//for(int i=1;i<MAX;i++) graph[i].clear();
	//memset(graph,0,sizeof(graph));
}

void dfs(int here){
	//if(bad[here]) return;	
	visited[here]=true;
	
	int next=graph[here];
	if(not visited[next]) dfs(next);					//visited 제어 구조를 이렇게도 할 수 있다.. 
	else if(not bad[next]){
		for(int i=next;i!=here;i=graph[i]){				// **** 인접행렬이라 가능한... *****
														// ********* 이분 그래프는 인접행렬이 훨씬 낫다... 말 그대로,원리적으로 dfs.***** 
			cnt++; 
		}cnt++;
	}
	bad[here]=true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int Q,n; cin>>Q;
	while(Q--){
		cin>>n;
		cnt=0;
		init();

		for(int i=1;i<=n;i++){
			//int tmp; cin>>tmp; 	
			//graph[i].push_back(tmp);
			cin>>graph[i];
		}
		
		for(int i=1;i<=n;i++){
			//if(bad[i] || visited[i]) continue;
			if(not visited[i]) dfs(i);
		}
		cout<<n-cnt<<"\n";

	}	
}
