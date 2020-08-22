#include <bits/stdc++.h>

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
using namespace std;
int n; 
vector<int> a,b;

const int MAX=101;
int dp[MAX][4];

//void print(){
//	for(int i=0;i<n;i++){
//		for(int j=0;j<=3;j++){
//			cout<<dp[i][j]<<" ";
//		}cout<<"\n";
//	}cout<<'\n';
//}

int solve(int day,int state){ 		//state =1 or 2 or 3 (init 0)
	if(day==n) return 0;
	int& ret= dp[day][state];
	if(ret!=-1) return ret;
	ret=0;
	
	if(state==1){
		if(b[day]) ret=max(ret,solve(day+1,2)+1);
		ret=max(ret,solve(day+1,3));
	}else if(state==2){
		if(a[day]) ret=max(ret,solve(day+1,1)+1);
		ret=max(ret,solve(day+1,3));
	}else if(state==3){
		if(a[day]) ret=max(ret,solve(day+1,1)+1);
		if(b[day]) ret=max(ret,solve(day+1,2)+1);
		ret=max(ret,solve(day+1,3));
	}
	
	///////////////////////
	if(state==0){
		ret=max(ret,solve(0,1));
		ret=max(ret,solve(0,2));
		ret=max(ret,solve(0,3));
	}
	
	return ret;
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	a=vector<int>(n);
	b=vector<int>(n);
	
	for(int i=0;i<n;i++){
		int tmp; cin>>tmp;
		if(tmp==0){
			a[i]=0,b[i]=0;
		}else if(tmp==1){
			a[i]=0,b[i]=1;
		}else if(tmp==2){
			a[i]=1,b[i]=0;
		}else{
			a[i]=1,b[i]=1;
		}
	}
	
	memset(dp,-1,sizeof(dp));
	int worked_day =solve(0,0);
	//cout<<worked_day<<'\n';
	cout<<n-worked_day<<"\n";
	
	//print();
}

