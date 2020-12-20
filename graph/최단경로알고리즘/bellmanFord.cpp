#include <bits/stdc++.h>
#define pii pair<int,int>
#define fs first
#define sc second

using namespace std;

const int MAX=510;
vector<pii> graph[MAX];		//graph[from] ={{to,cost}...}
vector<int> upper;
int V,m,w; 

bool reduce(){
	bool updated=false;
	for(int here=0;here<V;here++){
		for(int i=0;i<graph[here].size();i++){
			int to,cost;
			to=graph[here][i].fs,cost=graph[here][i].sc;
			if(upper[to]>upper[here]+cost){
				upper[to]=upper[here]+cost;
				updated=true;
			}
		}
	}
	return updated;
}

bool bellman_ford(int src){
	upper=vector<int>(V,1e9);
	upper[src]=0;
	
	//v번 완화 실행. 
	for(int _=1;_<=V-1;_++){	
		reduce();
	}
	bool updated=reduce();		//v번째 실행. cycle<=> v번째에도 d의 변화가 있다. 		
	
	if(updated) return false;		//negative cycle exists
	else return true; 				//no negative cycle exists	
}
