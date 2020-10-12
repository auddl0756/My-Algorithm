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

//const int LEN=110;
//int dp[LEN][LEN][2];	//n(idx),k(인접비트수:11),state
//int Q,n,k; 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int Q,n; cin>>Q;
	while(Q--){
		cin>>n;
		string S; cin>>S;
		vector<int> a;
		
		int nowlen=0;
		char now=S[0];
		for(int i=0;i<n;i++){
			if(now==S[i]) nowlen++;
			else{
				a.push_back(nowlen);
				nowlen=1;
				now=S[i];
			}
		} 
		a.push_back(nowlen);
		//debug(a);
		
		//두 포인터. 
		int s=0,e=0;	//e: s 이후 1이 아닌 수  중 가장 작은 인덱스 . 1이 아닌 수에서 1 빼주면 제일 앞의 1 하나만 지우면 되니 이득. 
		
		int ans=0;
		n=a.size();
		while(s<n){
			e=max(s+1,e);
			
			if(a[s]==1){
				if(e>=n || a[e]==1){
					if(e>=n-1){
						s+=2;
						ans++;
					}else{
						e++;	
					}
				}else{
					a[e]-=1;
					s++;
					ans++;
				}
			}else{
				ans++;
				s++;
			}		
		}
		
		cout<<ans<<"\n";
	}
		
}


