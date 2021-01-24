#include <bits/stdc++.h>
#define pii pair<int,int>
#define fs first
#define sc second

using namespace std;

const int MAX=2e5+10;
vector<int> tree[MAX];
int depth[MAX],sz[MAX],res[MAX];		//res[i] = sz[i]-depth[i] 
bool visited[MAX];

int main(){
	//dfs using lambda expression
	
	int n; cin>>n;
	for(int i=0;i<n-1;i++){
		int u,v; cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	depth[1]=1;
	
	function<int(int)> dfs = [&](int here){
		visited[here]=true;
		sz[here]++;
		
		for(int nxt:tree[here]){
			if(visited[nxt]==false){
				depth[nxt]=depth[here]+1;
				sz[here]+=dfs(nxt);
			} 
		}
		
		return sz[here];
	};
	
	
	dfs(1);
	for(int i=1;i<=n;i++) cout<<sz[i]<<" "; cout<<'\n';
	for(int i=1;i<=n;i++) cout<<depth[i]<<" "; cout<<'\n';
	
	
}


//about sort
//	vector<pii> a={{1,2},{1,3},{2,2},{2,3}};
//	
//	auto f=[](pii a,pii b)->bool{
//		if(a.sc>b.sc) return true;
//		else return false;
//	};
//	
//	sort(a.begin(),a.end(),f);
//	
//	for(pii x:a){
//		cout<<x.first<<' '<<x.second<<' ';
//	}cout<<'\n';
//	
//	sort(a.begin(),a.end(),[&](pii f,pii s){		//추천. 
//		if(f.sc<s.sc) return true;
//		else return false;	
//	});
//	
//	for(pii x:a){
//		cout<<x.fs<<' '<<x.sc<<' ';
//	}cout<<'\n';
//	
//	auto inrange = [&](int r,int c){			// 그래프 탐색 범위 검사에도 유용할듯. 
//		return (r>0 && r<5 && c>0 && c<5);	
//	};
//	
//	cout<<inrange(1,2)<<'\n';
