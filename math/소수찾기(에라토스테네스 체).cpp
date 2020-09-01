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
#define lb(arr,num) lower_bound(all(arr),num)

#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define msi map<string,int>

typedef long long ll;
using namespace std;
//typedef vector<vector<int> > matrix;

const int MAX=11000;
int prime[MAX]; 

//���� O(N) ����?  
void eratos(){
	for(int i=2;i<MAX;i++){
		if(prime[i]) continue;		//�Ҽ��� �� ���ٰ� ǥ���� �а��� �ٷ� ��ŵ. 
		prime[i]=i;	//�Ҽ�. 
		for(int j=i*2;j<MAX;j+=i) prime[j]=-1;		//���� �Ҽ��� �� ���� �͵��� -1�� ǥ��(������迡 �ִ� �͵�.) 
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int x; cin>>x;
	
	eratos();
	
	for(int i=2;i<=x;i++){
		cout<<prime[i]<<" ";
	}cout<<"\n";
}
