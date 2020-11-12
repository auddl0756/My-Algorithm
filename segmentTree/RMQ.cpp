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
using namespace std;

typedef long long ll;

//ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

//RMQ :Range Minimum Query

struct RMQ{
	int n;
	vector<int> rangeMin;
	//vector<int> rangeMax;		==>just reverse array and use rangeMin.
	
	RMQ(const vector<int>& arr){
		n=arr.size();
		rangeMin.resize(4*n);
		build(arr,0,n-1,1);
	}
	
	//node를 루트로 하는 서브트리를 초기화,이 구간의 최소값(RMQ)를 리턴. 
	int build(const vector<int>& arr,int left,int right,int node){
		if(left==right) return rangeMin[node]=arr[left];
		int mid=(left+right)/2;
		int leftMin=build(arr,left,mid,node*2);			//왼쪽 자식 
		int rightMin=build(arr,mid+1,right,node*2+1);	//오른쪽 자식 
		return rangeMin[node]=min(leftMin,rightMin);
	}
	
	int query(int left,int right,int node,int nodeleft,int noderight){
		//case 1: 교집합이 없을 때. 
		if(right < nodeleft || noderight<left) return 1e9;
		
		//case 2: node가 표현하는 범위가 arr[left,,right]에 완전히 포함되는 경우. 
		if(left<=nodeleft && noderight<=right) return rangeMin[node];
		
		//case 3: 그 이외 경우 :: node가 담당하는 구간이 검색 구간의 일부와 겹칠 때. 
		int mid=(nodeleft+noderight)/2;
		//분할정복처럼.. min(왼쪽쿼리,오른쪽쿼리) ==>  case 1 또는 2에 걸려서 값이 반환된다. 
		return min(query(left,right,node*2,nodeleft,mid),query(left,right,node*2+1,mid+1,noderight));	 
	}
	
	int query(int left,int right){
		return query(left,right,1,0,n-1);
	}
	
	//구간트리에서 1개의 값 업데이트+ 하는김에 구간의 최소값 반환. 
	int update(int idx,int newval,int node,int nodeleft,int noderight){
		//idx노드가 표현하는 구간과 상관없는 구간은 무시. 
		if(idx<nodeleft || noderight<idx) return rangeMin[node];
		
		//leaf까지 내려옴. 
		if(nodeleft==noderight) return rangeMin[node]=newval;
		int mid=(nodeleft+noderight)/2;
		
		//리프에서 올라가며 세그트리 업데이트. 
		return rangeMin[node]=min(update(idx,newval,node*2,nodeleft,mid),update(idx,newval,node*2+1,mid+1,noderight));
	}
	
	int update(int idx,int newval){
		return update(idx,newval,1,0,n-1);
	}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	RMQ rmq(a);	
	//debug(rmq.rangeMin);
	
	int Q; cin>>Q;
	while(Q--){
		int code,i,j,val; cin>>code;
		if(code==1){
			cin>>i>>val;
			//update
			i-=1;
			rmq.update(i,val);
		}else if(code==2){
			cin>>i>>j;
			i-=1,j-=1;
			//query
			cout<<rmq.query(i,j)<<"\n";
		}
	}	
}
