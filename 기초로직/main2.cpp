#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

#define debug(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<'\n';
template<typename F, typename S> ostream& operator << (ostream&, const pair<F, S>&);
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream&, const T_container&);

template<typename T> T gcd(T, T);
template<typename T> int lowerbound(vector<T>&, int , int , T);
vector<int> read(int);
vector<ll> readll(int);
string tostr(int);
int toint(string);


/**************************************************************************************************/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	set<int> sets;
	multiset<int> ms;
	map<int, int> mp;

	
	return 0;
}



/**************************************************************************************************/


template<typename T> T gcd(T a, T b) {
	if (b) return gcd(b, a % b);
	else return a;
}

template<typename T> int lowerbound(vector<T>& a, int s, int e, T tofind) {
	for (; s < e;) {
		int mid = (s + e) / 2;
		if (a[mid] >= tofind) e = mid;
		else s = mid+1;
	}
	return e;
}

string tostr(int x) { return to_string(x); }
int toint(string s) { return stoi(s); }

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

template<typename F, typename S> ostream& operator << (ostream& os, const pair<F, S>& o) {
	cout << '(' << o.first << ", " << o.second << ')';
	return os;
}

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) {
	cout << '{';
	for (const T& x : v) cout << x << ",";
	cout << '}';
	return os;
}
