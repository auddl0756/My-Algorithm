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
	
int dp[2600][2600];			//[s,e]������  �Ӹ�������� �Ǻ� 
ll dp2[2600];				//dp[n] = [1, n]������ �����ϴ� �ּ� ���� ��� ����
						
string p;

//	[S, E]������ �Ӹ�������� �Ǻ��ϴ� ���� ���� while���� ����մϴ�.
//	while�� ��� ��� ���·� ������ ������ �޸������̼��� ���ָ� ���� ������ �� O(N2)��,
//	�� ���¸��� O(1)�� ���� ���� �� �����Ƿ� O(N2)���� ��� ������ ���� �Ӹ�������� �Ǻ��� �� �ֽ��ϴ�.
	//  reference : https://justicehui.github.io/ps/2019/09/21/BOJ1509/
	
int checkPalindrome(int s,int e){
	if(s>=e) return 1;					//yes, it's palindrome. 
	
	int& ret=dp[s][e];
	if(ret!=-1) return ret;

	if(p[s]!=p[e]) return ret=0;			// not palindrome. mark as not palindrome(0) and finish checking.
	ret = checkPalindrome(s+1,e-1);	// continue checking.. 
	return ret;
}


//���� ������ �ּڰ��� ���ϴ� �͵� DP�� �� �� �ֽ��ϴ�.
ll seperate_into_palindromes(int idx){
	if(idx<0) return 0;
	
	ll& ret= dp2[idx];
	if(ret!=-1) return ret;
	ret=1e18;
	
	//j<i�� ��, j~i������ �Ӹ�����̴� => �ּ� �Ӹ���� ���� ���̴� dp[0][j-1]+1 �Ǵ� dp[0][i]�� �ȴ�.
	//~�̴� ~�ƴϴ� dp�� ����.
	 
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




