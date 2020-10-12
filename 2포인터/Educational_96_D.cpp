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
//int dp[LEN][LEN][2];	//n(idx),k(������Ʈ��:11),state
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
		
		//�� ������. 
		int s=0,e=0;	//e: s ���� 1�� �ƴ� ��  �� ���� ���� �ε��� . 1�� �ƴ� ������ 1 ���ָ� ���� ���� 1 �ϳ��� ����� �Ǵ� �̵�. 
		
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


