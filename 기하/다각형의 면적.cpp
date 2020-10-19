#include <bits/stdc++.h>

#define pii pair<int,int>
#define pdi pair<double,int>
#define ppi pair<pair<int,int>,int>
#define pipi pair<pair<int,int>,pair<int,int> >
#define pll pair<ll,ll>
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

using namespace std;

typedef long long ll;

//ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n; cin>>n;
	vector<pll> a(n);		//다각형을 이루는 꼭지점들의 좌표(점벡터). 정수 좌표에 대해서 구현. 
	for(int i=0;i<n;i++){
		cin>>a[i].fs>>a[i].sc;
	}
	
	ll tot=0;
	//외적을 다 합한 뒤에 절대값 취하고 2로 나누면 넓이. 
	for(int i=0;i<n;i++){
		tot+=(a[i].fs*a[(i+1)%n].sc - a[i].sc*a[(i+1)%n].fs);
	}
	
	bool flag=false;
	if(tot%2) flag=true;
	tot/=2;
	tot=llabs(tot);
	cout<<tot;
	if(flag) cout<<".5\n";
	else cout<<".0\n";
}

