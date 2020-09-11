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
//typedef vector<vector<int> > matrix;
#define pll pair<ll,ll>

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	deque<char> dq;	//deque는 벡터 업그레이드 버전.벡터같은 큐! 또 큐인데도 중간 위치에 원소를 삽입하거나 삭제할 수 있다
	
	vector<char> a;
	for(int i=0;i<26;i++) a.push_back(('a'+i));
	//debug(a);
	
	int cacheSize=3;
	for(int i=0;i<a.size();i++){
		if(dq.size()<cacheSize){
			dq.push_back(a[i]);
		}else{
			dq.pop_front();
			dq.push_back(a[i]);
		}
	} 
	
	dq.erase(dq.begin()+2);		//dqeue의 앞에서 3번째 원소 지우기. 
	
	for(int i=0;i<dq.size();i++) cout<<dq[i]<<" "; cout<<"\n"; 	//이렇게 인덱스로 참조도 가능. (큐에선 불가능한) 

}		
