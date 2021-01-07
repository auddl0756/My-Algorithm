#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

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

#define debug(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<'\n';
template<typename F, typename S> ostream& operator << (ostream&, const pair<F, S>&);
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream&, const T_container&);

ll gcd(ll, ll);
int lowerbound(vector<int>, int, int, int);
vector<int> read(int);
vector<ll> readll(int);
string tostr(int);
int toint(string);

/**************************************************************************************************/

struct Node {
	string type;  ll value; char op;
	Node(ll v) { type = "operand"; value = v; op = NULL; }
	Node(char c) { type = "operator"; value = 0; op = c; }
};

vector<Node> vec, stak;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	set<int> sets;
	map<char, int> mp;
	multiset<int> ms;

	//수식의 계산. 모든 연산자 우선순위에 따른 계산.
	//참고 : https://justicehui.github.io/ps/2020/12/06/YonseiU2020/

	//cin >> mp['+'] >> mp['-'] >> mp['*'] >> mp['/'];
	
	string s; cin >> s;		//수식

	vector<char> cc = { '+', '-', '*', '/' };
	vector<int> seq = { 0,1,2,3 };
	vector<char> order(4);
	//sort(all(order), [&](char a, char b) {return mp[a] > mp[b]; });

	ll ans = -1e10;

	do {
		for (int i = 0; i < 4; i++) {
			order[i] = cc[seq[i]];
		}
		//cout << order;

		vec.clear();
		stak.clear();

		ll now = 0;
		for (char c : s) {
			if ('0' <= c && c <= '9') now = now * 10 + char(c - '0');
			else {
				vec.push_back(now);
				vec.push_back(c);
				now = 0;
			}
		}
		//vec.push_back(now);
		vec.emplace_back(now);

		for (char c : order) {
			stak.clear();
			for (int i = vec.size() - 1; i >= 0; i--) {
				if (vec[i].type == "operator") stak.push_back(vec[i]);
				else if (stak.empty() || stak.back().op != c) stak.push_back(vec[i]);
				else {
					stak.pop_back();
					ll v = stak.back().value;
					stak.pop_back();
					if (c == '+') vec[i].value = vec[i].value + v;
					if (c == '-') vec[i].value = vec[i].value - v;
					if (c == '*') vec[i].value = vec[i].value * v;
					if (c == '/') vec[i].value = vec[i].value / v;
					stak.push_back(vec[i]);
				}
			}
			reverse(all(stak)); vec = stak;
		}

		//cout << vec[0].value << '\n';
		ans = max(ans, vec[0].value);
			
	} while (next_permutation(all(seq)));

	
	cout << ans << '\n';

	return 0;
}


/**************************************************************************************************/



ll gcd(ll a, ll b) {
	if (b) return gcd(b, a % b);
	else return a;
}

int lowerbound(vector<int> a, int s, int e, int tofind) {
	for (; s < e;) {
		int mid = (s + e) / 2;
		if (a[mid] >= tofind) e = mid;
		else s = mid + 1;
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

