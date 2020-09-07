#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta2(a,n) sort(a,a+n);
#define p(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define p2(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";

#define all(v) (v).begin(), (v).end()
#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))

int N; 
void print(auto pq){
	while(!pq.empty()){
		cout<<pq.top()<<" "; pq.pop();
	}cout<<"\n";	
}

void maxheap_int(){
	priority_queue<int> pq;								//default is maxheap
	//priority_queue<int,vector<int>,less<int> > pq;	//same with no parameter :: maxheap 
	for(int i=0;i<N;i++){
		int tmp; cin>>tmp; pq.push(tmp);
	}
	print(pq);
}

void minheap_int(){
	priority_queue<int,vector<int>,greater<int> >pq;	//for minheap, use greater<int> as 3rd parameter
	for(int i=0;i<N;i++){
		int tmp; cin>>tmp;
		pq.push(tmp);
	}
	print(pq);	
}

void minheap_pii(){
	priority_queue<pii,vector<pii>,greater<pii>> pq;	//also can used for type pair<int,int> as maxheap,minheap both.
	for(int i=0;i<N;i++){
		int tmp; cin>>tmp; pq.push({tmp,i});
	}
	while(!pq.empty()){
		cout<<pq.top().first<<" "<<pq.top().second<<"\n"; pq.pop();
	}
}

/////////////////////////////////////
// 구조체를 위한 priority_queue 사용법  
struct Obj{				
	int time;
	char state;
};

bool operator < (Obj a, Obj b){				// '<' operator 구현. '>'는 없다고 함. 구현체 내에서 부호를 바꿔야함. 
	if(a.time>b.time) return true;			//// 시간이 작을수록, 시간이 같을 때, state값이 작은 것이 먼저 나옴. 
	if(a.time==b.time){
		if(a.state>b.state) return true;
		else return false;
	}
	return false;
}

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>N;
//	maxheap_int();
//	minheap_int();
	minheap_pii();

	
	priority_queue<Obj> pq;
	Obj obj[5];
	for(int i=0;i<5;i++){
		obj[i].time=i+1;
		obj[i].state='a'+i;
		pq.push(obj[i]); 
	}
	
	Obj obj2; obj2.time=2,obj2.state='a';		
	pq.push(obj2);
	
	while(not pq.empty()){					
		Obj o=pq.top(); pq.pop();
		cout<<o.time<<" "<<o.state<<"\n";
	}
	
	

	
	 
}
