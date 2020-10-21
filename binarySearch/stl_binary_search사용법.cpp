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


// <STL>
//binary_search(arr_begin,arr_end,find_value) : 검색해주는 함수로서 찾는 값이 존재하면 true, 아니면 false를 리턴.

int main(){
	int n,tofind; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sorta(a);
	
	cin>>tofind;
	
	if(binary_search(all(a),tofind)){
		cout<<tofind<<" exists in array\n";
	}else{
		cout<<tofind<<" not exists in array\n";
	}
}

