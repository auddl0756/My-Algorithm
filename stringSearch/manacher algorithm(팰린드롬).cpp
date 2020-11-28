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
#define debug_pii(a) for(int i=0;i<a.size();i++) cout<<"("<<a[i].fs<<","<<a[i].sc<<") "; cout<<"\n";

#define all(v) (v).begin(), (v).end()
#define lb(arr,num) lower_bound(all(arr),num)

#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define msi map<string,int>

typedef long long ll;
using namespace std;

#define pll pair<ll,ll>
#define pcc pair<char,char>

const int MAX=1e6;
const int INF=1e9;

//manacher의 방법 :: 팰린드롬 찾는 법. **O(문자열 길이)** 
// input : 문자열
// result : 정수 배열 A 
//			(A[i]는 i를 중심으로 하는 가장 긴 팰린드롬의 반지름 길이)
//          (즉, S[i-A[i]] ... S[i+A[i]]가 팰린드롬)

//<example> 
// S = "banana"
// A = {0,0,1,2,1,0}

int n,A[MAX];
string s;		

void manachers(){
	int radius=0,p=0;
	for(int i=0;i<n;i++){
		if(i<=radius) A[i]=min(A[2*p-i],radius-i);	//앞에 있는 것들에 영향을 받는다면..
		else A[i]=0;    //앞에 있는 것이 영향을 못 준다면..
		
		while(i-A[i]-1>=0 && i+A[i]+1<n && s[i-A[i]-1]==s[i+A[i]+1] ) A[i]++;    //<- i ->로 뻗어나가.
		if(radius<i+A[i]) radius=i+A[i],p=i;        //radius는 왜 계속 유지되어 가지? 매번 0으론 안하네.. 좀 kmp같네..
	}
} 			
 			
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	string p; cin>>p;
	
	//"acc"에서 "cc" 같은 짝수 팰린드롬에 대응하려고 '#'을 사이사이에 추가함. 
	for(int i=0;i<p.size();i++){
		s+='#';
		s+=p[i];
	}
	s+='#';
	
	n=s.size();
	
	manachers();
	
//	debug2(A,n+1);

	int max_palindrome=1;
	for(int i=0;i<n;i++){
		max_palindrome = max(max_palindrome , A[i]);
	}
	
	cout<<max_palindrome<<'\n';
}




