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

const int MAX=2600;
const int INF=1e9;
	
int dp[2600][2600];			//[s,e]구간이  팰린드롬인지 판별 
ll dp2[2600];				//dp[n] = [1, n]구간을 분할하는 최소 개수 라고 정의
						
string p;

//	[S, E]구간이 팰린드롬인지 판별하는 것은 보통 while문을 사용합니다.
//	while문 대신 재귀 형태로 구현한 다음에 메모이제이션을 해주면 상태 공간은 총 O(N2)개,
//	각 상태마다 O(1)에 답을 구할 수 있으므로 O(N2)만에 모든 구간에 대해 팰린드롬인지 판별할 수 있습니다.
	//  reference : https://justicehui.github.io/ps/2019/09/21/BOJ1509/
	
int checkPalindrome(int s,int e){
	if(s>=e) return 1;					//yes, it's palindrome. 
	
	int& ret=dp[s][e];
	if(ret!=-1) return ret;

	if(p[s]!=p[e]) return ret=0;			// not palindrome. mark as not palindrome(0) and finish checking.
	ret = checkPalindrome(s+1,e-1);	// continue checking.. 
	return ret;
}


//분할 개수의 최솟값을 구하는 것도 DP로 할 수 있습니다.
ll seperate_into_palindromes(int idx){
	if(idx<0) return 0;
	
	ll& ret= dp2[idx];
	if(ret!=-1) return ret;
	ret=1e18;
	
	//j<i일 때, j~i까지가 팰린드롬이다 => 최소 팰린드롬 분할 길이는 dp[0][j-1]+1 또는 dp[0][i]가 된다.
	//~이다 ~아니다 dp의 일종.
	 
	for(int i=0;i<=idx;i++){
		if(dp[i][idx]) ret=min(ret,seperate_into_palindromes(i-1)+1);		
	}
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>p;
	int n= p.size();
	
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			checkPalindrome(i,j);
		}
	}
	
	//for debug
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<dp[i][j]<<"  ";
//		}cout<<'\n';
//	}cout<<'\n';
	
	memset(dp2,-1,sizeof(dp2));
	cout<<seperate_into_palindromes(n-1)<<'\n';
		
}




