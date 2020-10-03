//algorithm for finding minimun spanning tree's edge cost
//edge cost로 정렬하고 node들을 연결시키면 그것이 MST가 된다. 

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
#define lbd(arr,num) lower_bound(all(arr),num)

#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define msi map<string,int>

typedef long long ll;
using namespace std;
//typedef vector<vector<int> > matrix;
#define pll pair<ll,ll>
#define ppl pair<ll,pair<ll,ll>>

const int INF = (int)1e9 + 10;
const int MAX = 100001;
int V, E;

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


int main() {
	iosbase;
	cin >> V >> E;
	vector<ppl> edges;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c,{a,b} });
	}
	
	//sort by cost
	sorta(edges);
	
	//use disjoint set to check if node is connected
	Set *s = new Set();
	ll ansCost = 0;
	
	//***iterate for all edges ('E' times) ***
	for (int i = 0; i < E; i++) {
		int n1, n2,c;
		n1 = edges[i].sc.fs; n2 = edges[i].sc.sc; c = edges[i].fs;
		int p1, p2;
		p1 = s->find(n1); p2 = s->find(n2);
		if (p1 == p2) continue;

		s->merge(n1, n2);
		ansCost += c;
	}
	cout << (ll)cost << "\n";
	

}

