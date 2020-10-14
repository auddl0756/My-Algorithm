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

typedef long long ll;
using namespace std;
//typedef vector<vector<ll> > matrix;
#define pll pair<ll,ll>

vector<int> heap;		//1���� ���ͷ� heap ����ȭ. 

void upheap(int x){
	heap.push_back(x);
	int child=heap.size()-1;	//child idx
	int parent=(idx-1)/2;		//parent idx
	
	while(idx>0 && heap[child]>heap[parent]){	//�ڽ��� �� Ŭ ������ �ø��ϱ� maxheap 
		parent=(child-1)/2;
		swap(heap[child],heap[parent]);
		child=parent;
	}
}

int downheap(){		
	int ret;
	if(heap.empty()) return 0;
	ret=heap[0];			//���� ��Ʈ�� ���� 
	heap[0]=heap.back();	//���� ��Ʈ�� ���ŵ� �����̹Ƿ� �ϴ� ���� �ϴ�(���� �ϴ�?)�� ��Ʈ�� �ӽ� ����. 
	heap.pop_back();		//��Ʈ�� �ø��� ����. 
	
	int parent=0;
	int l,r;
	while(true){
		l=2*parent+1,r=2*parent+2;		//potential left child,right child
		if(l>=heap.size()) break;		//if left child overed range of heap size, then it has no child. so break.
		int child=parent;				//child which is selected between l and r
		if(heap[child]<heap[l]) child=l;
		if(r<heap.size() && heap[child]<heap[r]) nxt=r;
		if(parent==child) break;		//when no update is done, break. meaning parent>left child and parent>right child, in min heap
		
		swap(heap[parent],heap[child]);
		parent=child;
	}
	return ret;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++){
		int opcode; cin>>opcode;
		if(opcode){
			upheap(opcode);
		}else{
			int ret=downheap();
			cout<<ret<<'\n';
			
		}
	}
	
}



