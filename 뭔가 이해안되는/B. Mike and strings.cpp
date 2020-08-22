//이해 안 되네.. 
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

map<string,int> Map[51];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; string s;
	cin>>n;
	cin>>s; int sz=s.size();
	//cout<<s.substr(3)<<" "<<s.substr(3,4)<<'\n';		//index 3부터 4칸만큼 자른 문자열 반환. 
	for(int i=0;i<sz;i++){
		string tmp = s.substr(i,sz-i)+s.substr(0,i);
		//cout<<tmp<<'\n';
		if(Map[0].count(tmp)) continue;
		Map[0][tmp]=i;
	}
	
	for(int i=1;i<n;i++){
		cin>>s;
		for(int j=0;j<sz;j++){
			string tmp =s.substr(j,sz-j)+s.substr(0,j);
			if(Map[0].count(tmp)==0){
				cout<<-1<<'\n';
				return 0;
			}else{
				if(Map[i].count(tmp)) continue;
				Map[i][tmp]=j;	 
			}
		}
	}
	
	int ans=1e9;
	for(auto str:Map[0]){
		int cur=0;
		for(int i=0;i<n;i++){
			cur+=Map[i][str.first];
		}
		ans=min(ans,cur);
	}
	cout<<ans<<'\n';
	
}

