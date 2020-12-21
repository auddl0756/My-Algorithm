//boj 찾기 문제.
 
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

vector<int> failTable;		//실패함수(매핑)  테이블 
vector<int> res;			//패턴을 찾은 위치들. 

//아래와 같은로직인데 더 깔끔하고 의미를 살린 코드. 
void make_failTable(string pattern){
	int pl=pattern.size();
	failTable.resize(pl,0);
	int here=0;
	
	for(int nxt=1;nxt<pl;nxt++){
		while(here>0 && pattern[here]!=pattern[nxt]) 	//최대한 일치할 때 까지 줄여가는 과정 
			here=failTable[here-1];	
		
		if(pattern[here]==pattern[nxt]){	//그렇게 줄였는데 매치되었다-> 그럼 매치된 길이를 1증가시켜주자. 
			failTable[nxt]=here+1;
			here+=1;
		}
	}
}

//vector <int> make_failTable(string pattern) {
//	int pl = pattern.size();
//	//vector <int>failTable(pl, 0);
//	failTable.resize(pl,0);
//	int j = 0;
//	
//	for (int i = 1; i < pl; i++) {
//		while (j > 0 && pattern[i] != pattern[j]) {		//다르면 후퇴 
//			j = failTable[j - 1];	//==>quick
//			//j = 0;				//==>naive
//		}
//		if (pattern[i]==pattern[j]) {	//같으면 한보 전진. 
//			failTable[i] = j + 1;
//			j += 1;
//		}
//	}
//	return failTable;
//}

void KMP(string S, string pattern) {
	int sl = S.size(),pl=pattern.size();
	//vector<int> failTable = make_failTable(pattern);
	int j = 0;
	
	for(int i=0;i<sl;i++){						//검색대상 문자열의 인덱스 i는 앞으로 나아가기만 함.  
		while (j > 0 && S[i] != pattern[j]) 	//다르면 후퇴 
			j = failTable[j - 1];
		
		if (S[i] == pattern[j]) {			//여튼 매칭이 되고 있다. 
			if (j == pl - 1) {				//완전한 패턴을 발견했을 때! 
				res.push_back(i - (pl-1)); 	//답에 패턴이 발견된 S의 위치를 담고.  
				j = failTable[j];			//failTable 이용해 효율적으로 후퇴. 
			}else 							//아직 완전한 패턴을 발견하지 못했을 때. 
				j += 1;						//다음 매칭 시도. 	
		}
	}
	//return res;
}

int main() {
	string S,pattern;
//	cin >> S>>pattern;
	getline(cin,S);
	getline(cin,pattern);
	 
	failTable = make_failTable(pattern);
	
	//debug(failTable);

	//검색문자열 pattern이 검색 대상 문자열 S의 몇번째 위치에서 나타났는지를 담고 있음. 
	res = KMP(S, pattern);
	
	cout<<res.size()<<"\n";					//찾은 패턴의 갯수 
	for (int i = 0; i < res.size(); i++) {	//찾은 패턴의 시작위치들(인덱스+1) 
		cout << res[i]+1 << " ";
	}cout << "\n";

}
