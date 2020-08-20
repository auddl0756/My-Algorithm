#include <bits/stdc++.h>

using namespace std;

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
const int MAX=100001;

struct Tree{
	bool disrespect;
	vector<int> childs;
};

Tree tree[MAX];
vector<int> ans;
bool checked[MAX];
void dfs(int here,bool dis){
	//if(checked[here]) return;
	
	bool disflag=true;
	for(int i=0;i<tree[here].childs.size();i++){
		int next=tree[here].childs[i];
		bool next_dis=tree[next].disrespect;
		if(not(dis && next_dis)){
			disflag=false;
			//cout<<"here = "<<here<<" "<<next<<"\n";
			//ans.push_back(here);
			//checked[here]=true;
		}
		dfs(next,next_dis);
	}	
	if(disflag && dis && checked[here]==false){
		ans.push_back(here);
		checked[here]=true;
	}
	
}

void print(int root){
	queue<int> q;
	q.push(root);
	
	while(not q.empty()){
		int here=q.front(); q.pop();
		cout<<"here = "<<here+1<<"\n";
		for(int i=0;i<tree[here].childs.size();i++){
			int next=tree[here].childs[i];
			q.push(next); 
			
		}	
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
	int root;
	for(int i=0;i<n;i++){
		int par; cin>>par>>tree[i].disrespect;
		if(par==-1){
			root=i; continue;
		}
		//tree[par].push_back(i);
		tree[par-1].childs.push_back(i);
	}
//	print(root);
	dfs(root,tree[root].disrespect);
	sorta(ans);
	if(ans.size()==0) cout<<-1<<"\n";
	else for(int i=0;i<ans.size();i++) cout<<ans[i]+1<<" "; cout<<'\n';
	
	
}
	

