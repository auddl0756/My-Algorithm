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
	
	//node�� ��Ʈ�� �ϴ� ����Ʈ���� �ʱ�ȭ,�� ������ �ּҰ�(RMQ)�� ����. 
	int build(const vector<int>& arr,int left,int right,int node){
		if(left==right) return rangeMin[node]=arr[left];
		int mid=(left+right)/2;
		int leftMin=build(arr,left,mid,node*2);			//���� �ڽ� 
		int rightMin=build(arr,mid+1,right,node*2+1);	//������ �ڽ� 
		return rangeMin[node]=min(leftMin,rightMin);
	}
	
	int query(int left,int right,int node,int nodeleft,int noderight){
		//case 1: �������� ���� ��. 
		if(right < nodeleft || noderight<left) return 1e9;
		
		//case 2: node�� ǥ���ϴ� ������ arr[left,,right]�� ������ ���ԵǴ� ���. 
		if(left<=nodeleft && noderight<=right) return rangeMin[node];
		
		//case 3: �� �̿� ��� :: node�� ����ϴ� ������ �˻� ������ �Ϻο� ��ĥ ��. 
		int mid=(nodeleft+noderight)/2;
		//��������ó��.. min(��������,����������) ==>  case 1 �Ǵ� 2�� �ɷ��� ���� ��ȯ�ȴ�. 
		return min(query(left,right,node*2,nodeleft,mid),query(left,right,node*2+1,mid+1,noderight));	 
	}
	
	int query(int left,int right){
		return query(left,right,1,0,n-1);
	}
	
	//����Ʈ������ 1���� �� ������Ʈ+ �ϴ±迡 ������ �ּҰ� ��ȯ. 
	int update(int idx,int newval,int node,int nodeleft,int noderight){
		//idx��尡 ǥ���ϴ� ������ ������� ������ ����. 
		if(idx<nodeleft || noderight<idx) return rangeMin[node];
		
		//leaf���� ������. 
		if(nodeleft==noderight) return rangeMin[node]=newval;
		int mid=(nodeleft+noderight)/2;
		
		//�������� �ö󰡸� ����Ʈ�� ������Ʈ. 
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
