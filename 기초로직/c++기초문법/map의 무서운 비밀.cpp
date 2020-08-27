//Codeforces Round #640 (Div. 4) E. Special Elements
//https://codeforces.com/problemset/problem/1352/E
//*******************************************************//
// std::map 의 무서운 비밀
//http://egloos.zum.com/Aibaz/v/1656229

#include <bits/stdc++.h>

#define pii pair<int,int>
#define ppi pair<pair<int,int>,int>
#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta2(a,n) sort(a,a+n);

#define debug(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define debug2(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";

#define all(v) (v).begin(), (v).end()
#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define fi first
#define se second

typedef long long ll;
using namespace std;
map<int,int> Map;
map<int,bool> visited;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int Q,n; cin>>Q;
	while(Q--){
		cin>>n;
		vector<int> a(n);
		vector<int> prefix(n+1,0);
		Map.clear();
		visited.clear();
		
		for(int i=0;i<n;i++){
			 cin>>a[i];
			 Map[a[i]]++;
		}
		for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+a[i-1];
		
		int ansCnt=0;
		
		for(int div=2;div<=n;div++){
			for(int j=0;j+div<=n;j+=1){
				int key=prefix[j+div]-prefix[j];
					if(Map.count(key)){					//**********************************************************************
					//if(Map[key]){						//error : []연산자를 이용해서 map을 참조만 해도 메모리가 할당된다.. 
														// 참조연산자를 사용하는 대신 count() 또는 find()를 사용해야 한다. 
														//***********************************************************************
					if(visited[key]) continue;
					else{
						ansCnt+=Map[key]; visited[key]=true;
					}
				}
			}
		}
		
		cout<<ansCnt<<'\n';
		
	}
}
