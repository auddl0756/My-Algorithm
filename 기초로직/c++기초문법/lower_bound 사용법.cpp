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
	sorta(A);		//���ĵǾ� �̺�Ž�� ������.  
	
//	for(int i=0;i<A[];i++){
//		int tmp=(lower_bound(A.begin(),A.end(),A[i]) -A.begin());
//		cout<<A[i]<<"���� ����  ���� ���� : "<<tmp<<"\n";
//	}
	
	for(auto& a:A){
		int tmp=(lower_bound(A.begin(),A.end(),a)-A.begin());		//iterator�� ��ȯ. �������� A.begin()���� ���ָ� ������ index+1�� ���� �� �ִ�. 
		cout<<a<<"���� ���� ���� ���� : "<<tmp<<"\n";
	}
}
	

