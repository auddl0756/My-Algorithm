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

#define pll pair<ll,ll>

const int MAX=16,inf=1e9;
int n,src;					//�湮�� ��,����� 
int graph[MAX][MAX];		//�湮���� �Ÿ� 
int dp[MAX][1<<MAX];		//(���� ��ġ,�������� �湮����ǥ���� ����) 

//bitmask DP
//n<=16�� ��. �κ� ������ �� : N*(2^N)

// args : here = ������ġ , visited = �湮 ���� 
// return : here���� �����ϴ� �κ� ����� �ּ� ���� ��ȯ 

int shortestPath(int here,int visited){
	//base case 
	if(visited == (1<<n)-1) return graph[here][src];		//(1<<n)-1 ==111...11 :: meaning visited all nodes.
	
	int& ret=dp[here][visited];
	if(ret!=-1) return ret;
	ret=inf;
	
	for(int nxt=0;nxt<n;nxt++){
		//�湮�� ���� skip 
		if(visited&(1<<nxt)) continue;
		
		int candidatePath = graph[here][nxt] +shortestPath(nxt,visited|(1<<nxt));	//bit�������� �湮ó���ϴ� ���. 
		ret=min(ret,candidatePath);
	}
	
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
			if(graph[i][j]==0) graph[i][j]=inf;
		}
	}
	
	int ans=inf;
	
	for(int i=0;i<n;i++){
		memset(dp,-1,sizeof(dp));
		src=i;
		ans=min(ans,shortestPath(i,(1<<i)));
	}
	
	cout<<ans<<'\n';
}	



