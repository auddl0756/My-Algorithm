#include <iostream>
#include <algorithm>
#include <queue>

#define pii pair<int,int>
const int INF=1e9;

int V,E;
const int MAX=1001;
vector<pii>graph[MAX];
int trace[MAX];

void di(int src){
	vector<int>dist(MAX,INF);
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.push({src,0});
	dist[src]=0;

	while(pq.empty()==false){
		int here,cost;
		here=pq.top().first;
		cost=pq.top().second;
		pq.pop();

		if(dist[here]<cost) continue;

		for(int i=0;i<graph[here].size();i++){
			int next,nextDist;
			next=graph[here][i].first;
			nextDist=graph[here][i].second+cost;
			if(dist[next]>nextDist){
				dist[next]=nextDist;
				pq.push({next,nextDist});
				trace[next]=here;
			}
		}
	}
}

int main(){
	cin>>V>>E;
	while(E--){
		int from,to,cost;
		cin>>from>>to>>cost;
		graph[from].push_back({to,cost});
		graph[to].push_back({from,cost});
	}

	di(1);

	for(int i=2;i<=V;i++)
		cout<<i<<" "<<trace[i]<<"\n;";
}
