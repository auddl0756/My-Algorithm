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

//brute force search 'gcd' , O(N)
int getgcd1(int a,int b){
	int r=min(a,b);
	for(int i=r;i>=1;i--){
		if(a%i==0 && b%i==0) return i;
	}
}

//<  유클리드의 방법 >
//두 자연수 A, B (A > B)가 있고, A를 B로 나눴을 때 나머지를 r이라 하면, gcd(A, B) = gcd(B, r) 이다. (r이 0이 되기 전까지)
//참고: https://onsil-thegreenhouse.github.io/programming/algorithm/2018/04/01/gcd/
//O(logN)
int getgcd2(int a,int b){
	if(b>a) swap(a,b);
	if(a%b==0) return b;
	else return getgcd2(b,a%b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a,b; cin>>a>>b;
	
	cout<<getgcd1(a,b)<<"\n";
	cout<<getgcd2(a,b)<<"\n";
}


