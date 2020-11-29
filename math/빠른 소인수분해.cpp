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
#define debug_pii(a) for(int i=0;i<a.size();i++) cout<<"("<<a[i].fs<<","<<a[i].sc<<") "; cout<<"\n";

#define all(v) (v).begin(), (v).end()
#define lb(arr,num) lower_bound(all(arr),num)

#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define msi map<string,int>

typedef long long ll;
using namespace std;

#define pll pair<ll,ll>
#define pcc pair<char,char>

const int MAX=5e6+10;
const int INF=1e9;

//에라토스체 ->  소수 구함 + 조금 응용해서 어떤 수의 minimum factor를 기록해둠. 
// 소인수 분해 -> 그렇게 기록해둔 minimum factor로 수가 1이 아닐때까지 나눠가면 매우 빠름. 

int minfactor[MAX];

void eratos(){
	for(int i=2;i<MAX;i++){
		if(minfactor[i]!=0) continue;

		for(int j=i;j<MAX;j+=i){
			 if(minfactor[j]) continue;
			 minfactor[j]=i;
		}
	}	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int Q; cin>>Q; 
	
	eratos(); 	//o(n)	 
	
	while(Q--){	 
		int k; cin>>k;
		
		while(k!=1){
			cout<<minfactor[k]<<" ";
			k/=minfactor[k];
		}cout<<'\n';		

	}
}



