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
#define pcc pair<char,char>

const int MAX=100;	//10000���� 
const int INF=1e9;

int capacity[MAX][MAX],flow[MAX][MAX],trace[MAX];	//�뷮,����,������� ���� �� �湮����(before)
int V,E;
//vector<int> graph[MAX];

void bfs(int src,int sink){
	memset(trace,-1,sizeof(trace));		//-1 means not visited
	queue<int> q;
	trace[src]=src;
	q.push(src);
	
	while(not q.empty() && trace[sink]==-1){
		int here=q.front(); q.pop();

		//������� ��� 
		for(int nxt=0;nxt<=V;nxt++){
			if(capacity[here][nxt] - flow[here][nxt] <=0 || trace[nxt]!=-1) continue;				
			q.push(nxt);
			trace[nxt]=here;
		}
	}		
}


// ��ƮǮĿ��? ����յ� ī��? ���� ���� �� ������ ��¶�� ���Ʈ���� �׸�������� �ִ� ���� ã�� �˰���. 
//<�˰���> 
// 1. ��� ������� ã��
//	 a) ã�� ������η� ������� �ּ� ���� ã��
//	 b) �ּ� ������ �� ������η�  ��������� 
// 2. ������� ��ã������ ����.

int maxFlow(int src,int sink){
	int totalFlow=0; 
	memset(flow,0,sizeof(flow));
	 
	while(true){
		//������� ã�� 
		bfs(src,sink);	
		
		//������� �� ã�� <==> network�� �ִ� ������ �����Ǿ���
		if(trace[sink]==-1) break;		
		int flow_amount =INF;
		
		//���� ��θ� ���� ������ �󸶳� ������ ���ϱ� (�ּҷ�  ���ݾ� �����°� �����̶� �ּҰ��� ã�´�) 
		for(int p=sink;p!=src;p=trace[p]){
			flow_amount = min(flow_amount,capacity[trace[p]][p] - flow[trace[p]][p]);
		}
		
		//���� ��θ� ���� ������ ������
		for(int p=sink;p!=src;p=trace[p]){
			flow[trace[p]][p]+=flow_amount;
			flow[p][trace[p]]-=flow_amount;
		}	
		totalFlow+=flow_amount;
		
	}
	
	return totalFlow;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	V='z'-'A';
	cin>>E;
	for(int i=0;i<E;i++){
		char u,v; int c;
		cin>>u>>v>>c;
		capacity[u-'A'][v-'A']+=c;
		capacity[v-'A'][u-'A']+=c;
	}

	cout<<maxFlow(0,'Z'-'A')<<'\n';		
}	





 


