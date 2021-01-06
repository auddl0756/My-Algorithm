#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <set>
#include <map>

typedef long long ll;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ppi pair<int, pair<int, int> >
#define pipi pair<pair<int, int>, pair<int, int> >

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fs first
#define sc second
#define sorta(x) sort(all(x)) 
#define rsorta(x) sort(rall(x)) 
#define lb lower_bound

#define debug(a) for(int i=0;i<(int)a.size();i++) cout<<a[i]<<" "; cout<<'\n';
#define debugn(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<'\n';
#define debug2(a) for(int i=0;i<(int)a.size();i++) cout<<"("<<a[i].fs<<","<<a[i].sc<<") "; cout<<"\n";

using namespace std;

ll gcd(ll,ll);
int lowerbound(vector<int>, int, int, int);
vector<int> read(int );
vector<ll> readll(int);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	set<int> sets;
	map<int, int> mp;
	multiset<int> ms;

	int Q; cin >> Q;
	while (Q--) {
		int n; cin >> n;
		vector<int> a = read(n);
		
	}
}


/**************************************************************************************************/
ll gcd(ll a, ll b) {
	if (b) return gcd(b, a % b);
	else return a;
}

int lowerbound(vector<int> a, int s, int e, int tofind) {
	for (;s < e;) {
		int mid = (s + e) / 2;
		if (a[mid] >= tofind) e = mid;
		else s = mid + 1;
	}
	return e;
}

vector<int> read(int n) {
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	return a;
}

vector<ll> readll(int n) {
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	return a;
}