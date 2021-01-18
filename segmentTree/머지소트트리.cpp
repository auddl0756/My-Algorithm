#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()

using namespace std;

const int MAX=1e5+10;
vector<int> tree[MAX*2];
vector<int> a;
int n;

void build(){
	for(int i=0;i<n;i++) tree[n+i].push_back(a[i]);		//binary 인덱스트리에서 하던 것처럼. 
	
	for(int i=n-1;i>0;i--){
		tree[i].resize(tree[i<<1].size() + tree[i<<1|1].size());
		merge(all(tree[i<<1]),all(tree[i<<1|1]),tree[i].begin());	//stl
	}
}

int query(int l,int r,int k){		//[l,r)구간에서 k 이하인 것의 개수 반환.  
	l+=n,r+=n;
	int res=0;
	for(;l<r;l>>=1,r>>=1){
		if(l&1) res+=lower_bound(all(tree[l]),k+1)-tree[l].begin(),l++;
		if(r&1) r--,res+=lower_bound(all(tree[r]),k+1)-tree[r].begin();
	}
	return res;
}


// 참고 : https://justicehui.github.io/medium-algorithm/2020/02/25/merge-sort-tree/ 
// 세그먼트 트리는 분할 정복을 메모이제이션하는 자료구조라고 할 수 있고,
// 머지 소트 트리는 세그먼트 트리의 각 노드에서,
// 해당 노드가 관리하는 구간에 있는 모든 원소들을 정렬한 상태로 저장하고 있습니다.

//binary인덱스 트리와 거의 동일한 구조인데 각 노드가 배열일뿐임.
//구간에서 k이하인거 몇개인지 같은거 구하기 좋음. 

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
