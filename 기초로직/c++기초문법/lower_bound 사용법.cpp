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

bool comp(pii a,pii b){
	return a.fs <b.fs;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N; cin>>N;
	vector<int> A(N);
	int B[10000];
	vector<pii> C(N);
	
	for(int i=0;i<N;i++){
		cin>>A[i]; 
		B[i]=A[i];
		C[i].fs=A[i],C[i].sc=0;
	} 
	
	sorta(A); sorta2(B,N);	sorta(C);
	//정렬되야 이분탐색 가능함.  
	
	//for vector<int>
	for(auto& a:A){			
		int idx=lower_bound(all(A),a)-A.begin();		//iterator를 반환. 시작점인 A.begin()에서 빼주면 하한의 index+1을 얻을 수 있다. 
		cout<<a<<" 보다 작은 수의 갯수 : "<<idx<<"\n";
	}
	
	//for array(배열) 
	for(int i=0;i<N;i++){
		int b=B[i];
		int idx=lower_bound(B,B+N,b)-B;
		cout<<b<<" 보다 작은 수의 갯수 : "<<idx<<"\n"; 
	}
	
	//for vector<pii>. give lower_bound 4th argument, comparator.
	for(auto& c:C){
		int idx=lower_bound(all(C),c,comp)-C.begin();
		cout<<c.fs<<" 보다 작은 수의 갯수 : "<<idx<<"\n"; 
	}
	
}
