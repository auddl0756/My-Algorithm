#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta2(a,n) sort(a,a+n);
#define p(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define p2(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N; cin>>N;
	vector<int> A(N);
	for(int i=0;i<N;i++) cin>>A[i];
	sorta(A);		//정렬되야 이분탐색 가능함.  
	
//	for(int i=0;i<A[];i++){
//		int tmp=(lower_bound(A.begin(),A.end(),A[i]) -A.begin());
//		cout<<A[i]<<"보다 작은  수의 갯수 : "<<tmp<<"\n";
//	}
	
	for(auto& a:A){
		int tmp=(lower_bound(A.begin(),A.end(),a)-A.begin());		//iterator를 반환. 시작점인 A.begin()에서 빼주면 하한의 index+1을 얻을 수 있다. 
		cout<<a<<"보다 작은 수의 갯수 : "<<tmp<<"\n";
	}
}
	

