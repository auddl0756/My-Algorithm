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
#define ppl pair<pll,ll>

//https://www.acmicpc.net/problem/10165

bool comp(ppi a,ppi b){		//������ġ��  ���������� ����, ���ٸ� ������ġ��  �� �� ����  �տ� ������ ����. 
	if(a.fs.fs<b.fs.fs) return true;
	else if(a.fs.fs==b.fs.fs){
		if(a.fs.sc>b.fs.sc) return true;
		else return false;
	}
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m; cin>>n>>m;
	vector<ppi> a;	//pair<pair<ll,ll>,ll> ::  ������ġ,������ġ,�뼱��ȣ 
	vector<ppi> R,I;
	
	for(int i=0;i<m;i++){
		//�Է¹����鼭 ���� ������ ���������� ��ȯ. 
		int x,y,z; cin>>x>>y; z=i+1;
		if(x>y){
			a.push_back({{x-n,y},z});	//��ⷯ �յ�. 
			a.push_back({{x,y+n},z});
		}else{
			a.push_back({{x,y},z});
		}
		
	}
	
	sort(all(a),comp);
//	for(int i=0;i<a.size();i++){
//		cout<<a[i].fs.fs<<" "<<a[i].fs.sc<<" "<<a[i].sc<<"\n";
//	}
	
	//case 1: R in R
	//case 2: R in I
	//case 3: I in I
	
	set<int> ans;
	int nowend=-n;
	for(int i=0;i<a.size();i++){
		if(nowend<a[i].fs.sc){
			ans.insert(a[i].sc);
			nowend=a[i].fs.sc;
		}
	}
	
	vector<int> res(all(ans));
	debug(res);
	
}

//����: https://blog.naver.com/pasdfq/221251549101 
