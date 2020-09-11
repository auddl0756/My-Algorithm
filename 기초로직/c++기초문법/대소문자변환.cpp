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

vector<string> LOWER(vector<string>& strs){
	for(int i=0;i<strs.size();i++){
		for(int j=0;j<strs[i].size();j++){
			strs[i][j]=tolower(strs[i][j]);
		}
	}
	return strs;
}

vector<string> UPPER(vector<string>& strs){
	for(int i=0;i<strs.size();i++){
		for(int j=0;j<strs[i].size();j++){
			strs[i][j]=toupper(strs[i][j]);
		}
	}
	return strs;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<string> a={"AaBb","CcDd","XXXXxxxx"}; 
	vector<string> lowers=LOWER(a);
	vector<string> uppers=UPPER(a);
	debug(lowers);
	debug(uppers);
}		
