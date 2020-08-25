//C. Yet Another Counting Problem
//Educational Codeforces Round 86 (Rated for Div. 2)
//https://codeforces.com/contest/1342/problem/C

#include <bits/stdc++.h>

#define pii pair<int,int>
#define ppi pair<pair<int,int>,int>
#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta2(a,n) sort(a,a+n);

#define p(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define p2(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";

//#define all(v) (v).begin(), (v).end()
#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define fi first
#define se second

typedef long long ll;
using namespace std;

//l,r은 매우 큰데 a,b는 작다는 점이 눈에 들어오긴 했는데... 
//주기가 있었다. 왜 주기는 생각하지 못했지. 

//*********정수론 문제는 몫과 나머지에 초점을 맞추자. **********

const int MAX=201*201;
bool bucket[MAX];
ll prefix[MAX+10];
ll Q,a,b,x,l,r;
ll len;
ll all;

void precalc(){				
	len=a*b;
	for(int i=1;i<len;i++){
		if((i%a)%b != (i%b)%a) bucket[i]=true;
	}
	for(int i=1;i<len;i++){
		prefix[i]=prefix[i-1]+bucket[i];
	}
	all =prefix[len-1];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	 cin>>Q;
	int q;
	while(Q--){
		cin>>a>>b>>q;
		memset(bucket,false,sizeof(bucket));
		memset(prefix,0,sizeof(prefix));
		
		precalc();
		
		while(q--){
			cin>>l>>r;
			ll mok_r,mok_l,res_r,res_l;
			
			mok_r = r/len; mok_l = l/len;
			res_r = r%len, res_l =l%len;
			
			ll left,right;
			
			if(res_l==0) left=all*1ll*mok_l;
			else left = all*1ll*mok_l +prefix[res_l-1];
			right=all*1ll*mok_r + prefix[res_r];
			cout<<right-left<<" ";
			
		}
		cout<<"\n";
	}

}



