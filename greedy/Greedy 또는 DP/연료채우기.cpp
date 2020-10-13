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

//map<int,int> mp; 
//int cur[1000010];
int n;
vector<pii> a;
bool visited[10100];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	a=vector<pii>(n);
	for(int i=0;i<n;i++){
		cin>>a[i].fs>>a[i].sc;
	}	
	
	int gas,dst;
	cin>>dst>>gas;
	a.push_back({dst,0});
	
	sorta(a);	//size =n+1
	
	ll nowgas=gas;
	int x=-1;
	int anscnt=0;
	
	priority_queue<int> pq;
	for(int i=0;i<a.size();){	
		int d=a[i].fs-(x==-1 ? 0:a[x].fs);
		//cout<<x<<' '<<nowgas<<'\n';
		
		if(d>nowgas){
			if(pq.empty()){
				cout<<-1<<"\n";
				return 0;
			}else{
				nowgas+=pq.top();	//가장 많은 연료통 사용. 
				
				pq.pop();
				anscnt++;		//주유소 들린 효과. 
			}
		}else{
			//nowx=a[i].fs;	
			x=i;
			if(not visited[x]){
				pq.push(a[x].sc);	//일단 주유소에 들르면 연료 담아.  쓸지말지는 나중에 결정. 
				visited[x]=true;
			}	
			nowgas-=d;
			i++;
		}
	}
	cout<<anscnt<<"\n";
}


