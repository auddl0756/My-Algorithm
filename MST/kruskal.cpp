//algorithm for finding minimun spanning tree's edge cost
//edge cost로 정렬하고 node들을 연결시키면 그것이 MST가 된다. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long;
#define pii pair<int,int>
const int INF = (int)1e9 + 10;
const int MAX = 100001;

//disjoint set class
class Set {
private :
	int parent[MAX];

public:
	Set() {
		for (int i = 0; i < MAX; i++)
			parent[i] = i;
	}

	int find(int idx) {
		if (idx == parent[idx]) return idx;
		return parent[idx] = find(parent[idx]);
	}

	void merge(int idx1, int idx2) {
		int p1, p2;
		p1 = find(idx1); p2 = find(idx2);
		if (p1 == p2) return;
		
		parent[p1] = p2;
	}

};

int V, E;

int main() {
	iosbase;
	cin >> V >> E;
	vector < pair<ll,pii> > edges;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c,{a,b} });
	}
	
	//sort by cost
	sort(edges.begin(), edges.end());
	int lastEdgecost = 0;
	
	//use disjoint set to check if node is connected
	Set *s = new Set();
	ll ansCost = 0;
	
	//***iterate for all edges ('E' times) ***
	for (int i = 0; i < E; i++) {
		int n1, n2,c;
		n1 = edges[i].second.first; n2 = edges[i].second.second; c = edges[i].first;
		int p1, p2;
		p1 = s->find(n1); p2 = s->find(n2);
		if (p1 == p2) continue;

		s->merge(n1, n2);
		ansCost += c;
	}
	cout << (ll)cost << "\n";


}

