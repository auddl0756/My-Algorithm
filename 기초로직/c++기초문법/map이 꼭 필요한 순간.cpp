// Codeforces Round #653 (Div. 3) 
// https://codeforces.com/contest/1374/problem/D

#include <bits/stdc++.h>

#define pii pair<int,int>
#define ppi pair<pair<int,int>,int>
#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta2(a,n) sort(a,a+n);

#define p(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define p2(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";

#define all(v) (v).begin(), (v).end()
#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define fi first
#define se second

typedef long long ll;
using namespace std;

const int MAX=2*100001;
//int bucket[MAX];		//k가 10^9까지 될 수 있어서 단순 배열로 count하면 메모리 터진다.. 
map<int,int> bucket;	//std::map이 꼭 필요한 순간.... 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll Q,n,k; cin>>Q;
	while(Q--){
		cin>>n>>k;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			 cin>>a[i], a[i]%=k;
			 //if(a[i]==0) a[i]+=k;
			 if(a[i]==0) continue;
			 a[i]=k-a[i];
		}

		//memset(bucket,0,sizeof(bucket));
		bucket.clear();
		
		int rotate=1,argmax=0;
		for(int i=0;i<n;i++){
			if(a[i]==0) continue;
			bucket[a[i]]++;
			rotate=max(rotate,bucket[a[i]]);
//			if(rotate <=bucket[a[i]]){
//				rotate=bucket[a[i]];
//				argmax=max(argmax,a[i]);
//			}
		}

		
		for(int i=0;i<n;i++){
			if(a[i]==0) continue;
			if(bucket[a[i]]==rotate) {
				argmax=max(argmax,a[i]);
			}
		}
		
		if(rotate==1 && argmax==0){
			cout<<0<<'\n'; continue;
		}
		
		ll ans=1;
		ans+=(rotate-1)*(k-1);
		ans+=rotate-1;
		ans+=argmax;
		cout<<ans<<'\n';
		
	}
	
}

