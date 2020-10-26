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
using namespace std;

typedef long long ll;

//ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int b[100000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
	vector<int> a(n);
	 
	for(int i=0;i<n;i++){
		 cin>>a[i];
		 b[i]=a[i];
	}
	
	//for vector
	cout<<*max_element(all(a))<<"\n";
	cout<<*min_element(all(a))<<"\n";
	
	//for array
	cout<<*max_element(b,b+n)<<"\n";
	cout<<*min_element(b,b+n)<<"\n";
	
	
}

