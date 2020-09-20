#include <bits/stdc++.h>

#define pii pair<int,int>
#define ppi pair<pair<int,int>,int>
#define pipi pair<pair<int,int>,pair<int,int> >
#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta2(a,n) sort(a,a+n);

//#define debug(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define debug(a) for(int ii=0;ii<a.size();ii++) cout<<a[ii]<<" ";cout<<"\n";
#define debug2(a,n) for(int ii=0;ii<n;ii++)cout<<a[ii]<<" ";cout<<"\n";

#define all(v) (v).begin(), (v).end()
#define lb(arr,num) lower_bound(all(arr),num)

#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define fs first
#define sc second

typedef long long ll;
using namespace std;
//typedef vector<vector<int> > matrix;
#define pll pair<ll,ll>
#define psi pair<string,int>

//in #include <numeric>
//std::accumulate(v.begin(),v.end(),initial value of sum)


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<int> a={1,2,3,4,5,6,7,8,9,10};
	
	cout<<accumulate(all(a),0)<<"\n";	//for int type
	
	vector<ll> b={(ll)1e12,(ll)1e12+1,(ll)1e12+2,(ll)1e12+3};		//for long long type
	cout<<accumulate(all(b),0LL)<<"\n";
}
