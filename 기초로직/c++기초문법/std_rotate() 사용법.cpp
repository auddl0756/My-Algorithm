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

void print(vector<int>& a){	//출력용 
	for(int i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<'\n';
}

void print(int a[],int n){	//출력용 
	for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;

	int a[100];
	memset(a,0,sizeof(a));
	vector<int> b(n);
	for(int i=0;i<n;i++){
		cin>>a[i]; b[i]=a[i];
	}
	
	//rotate for array
	rotate(a,a+1,a+n);			//  <<-로 1칸 회전 
	print(a,n);	
	rotate(a,a+n-1,a+n);		// 	-->로 1칸 회전 
	print(a,n);
	
	cout<<"\n\n";
	
	//rotate for vector
	print(b);
	rotate(b.begin(),b.begin()+1,b.end());		//<--로 1칸 회전 
	print(b);
	
	rotate(b.begin(),b.begin()+n-1,b.end());	//-->로 1칸 회전 
	print(b);
}



