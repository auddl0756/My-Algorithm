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

int n;
int graph[11][11];

//n<=10일 때. ->시간복잡도 :(n-1)!
//완전탐색 
//path가 지금까지 만든 경로일 때,나머지 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환 
int shortestPath(vector<int>& path,vector<bool>& visited,int curdist){
	if(path.size()==n){
		return curdist+graph[path.back()][path[0]];
	}
		
	int ret=1e9;
	
	for(int nxt=0;nxt<n;nxt++){
		if(visited[nxt]) continue;
		int here=path.back();
		
		path.push_back(nxt);
		visited[nxt]=true;
		
		int candidatePath = shortestPath(path,visited,curdist+graph[here][nxt]);		
		
		ret=min(ret,candidatePath);
		visited[nxt]=false;
		path.pop_back();
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
		}
	}
	
	vector<int> path={0};
	vector<bool> visited(n,false);
	visited[0]=true;
	
	cout<<shortestPath(path,visited,0);	
}	



