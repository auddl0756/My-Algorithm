#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()

using namespace std;

const int MAX=1e5+10;
vector<int> tree[MAX*2];
vector<int> a;
int n;

void build(){
	for(int i=0;i<n;i++) tree[n+i].push_back(a[i]);		//binary �ε���Ʈ������ �ϴ� ��ó��. 
	
	for(int i=n-1;i>0;i--){
		tree[i].resize(tree[i<<1].size() + tree[i<<1|1].size());
		merge(all(tree[i<<1]),all(tree[i<<1|1]),tree[i].begin());	//stl
	}
}

int query(int l,int r,int k){		//[l,r)�������� k ������ ���� ���� ��ȯ.  
	l+=n,r+=n;
	int res=0;
	for(;l<r;l>>=1,r>>=1){
		if(l&1) res+=lower_bound(all(tree[l]),k+1)-tree[l].begin(),l++;
		if(r&1) r--,res+=lower_bound(all(tree[r]),k+1)-tree[r].begin();
	}
	return res;
}


// ���� : https://justicehui.github.io/medium-algorithm/2020/02/25/merge-sort-tree/ 
// ���׸�Ʈ Ʈ���� ���� ������ �޸������̼��ϴ� �ڷᱸ����� �� �� �ְ�,
// ���� ��Ʈ Ʈ���� ���׸�Ʈ Ʈ���� �� ��忡��,
// �ش� ��尡 �����ϴ� ������ �ִ� ��� ���ҵ��� ������ ���·� �����ϰ� �ֽ��ϴ�.

//binary�ε��� Ʈ���� ���� ������ �����ε� �� ��尡 �迭�ϻ���.
//�������� k�����ΰ� ����� ������ ���ϱ� ����. 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >>n;
	a=vector<int>(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	build();
	
	int Q; cin>>Q;
	while(Q--){
		int l,r,k; cin>>l>>r>>k;
		cout<<query(l,r+1,k)<<"\n";
	}
}
