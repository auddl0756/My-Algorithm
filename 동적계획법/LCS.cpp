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

//https://www.crocus.co.kr/787 ���� 
// LCS�� ���� ���ϱ�
// Longest Common Subsequence(���� �κ� ����)

const int MAX=5050;

int dp[MAX][MAX];	//lcs ���� ����� 
string s,p; 		//�� ���ڿ� s,p 

//������ 
void print(){
	for(int i=0;i<=s.size();i++){
		for(int j=0;j<=p.size();j++){
			cout<<dp[i][j]<<" ";
		}cout<<'\n';
	}cout<<'\n';
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>s>>p;
	int lcs=0;	

	//�� ���ڿ����� 2���� ���̺� ������� ��, 
	for(int i=0;i<s.size();i++){
		for(int j=0;j<p.size();j++){
			if(s[i]==p[j]) dp[i+1][j+1]=dp[i][j]+1;			//������ �� �¾ҳ�. �׷� �� �ε����� ���++ �ϰ� ���̴� 1�����ϸ� ����. 
			else{
				dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);	//�ٸ���. �׷� ���̺��� ������ ���ų� ���ʿ��� �� �� �߿� �ִ�. 
			}
			lcs=max(lcs,dp[i+1][j+1]);
		}
	}
	
	cout<<lcs<<'\n';	//lcs == dp[s.size()][p.size()] 
	//cout<<dp[s.size()][p.size()]<<'\n';
	print();
}


