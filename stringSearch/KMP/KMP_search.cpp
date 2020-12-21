//boj ã�� ����.
 
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

vector<int> failTable;		//�����Լ�(����)  ���̺� 
vector<int> res;			//������ ã�� ��ġ��. 

//�Ʒ��� ���������ε� �� ����ϰ� �ǹ̸� �츰 �ڵ�. 
void make_failTable(string pattern){
	int pl=pattern.size();
	failTable.resize(pl,0);
	int here=0;
	
	for(int nxt=1;nxt<pl;nxt++){
		while(here>0 && pattern[here]!=pattern[nxt]) 	//�ִ��� ��ġ�� �� ���� �ٿ����� ���� 
			here=failTable[here-1];	
		
		if(pattern[here]==pattern[nxt]){	//�׷��� �ٿ��µ� ��ġ�Ǿ���-> �׷� ��ġ�� ���̸� 1������������. 
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
//		while (j > 0 && pattern[i] != pattern[j]) {		//�ٸ��� ���� 
//			j = failTable[j - 1];	//==>quick
//			//j = 0;				//==>naive
//		}
//		if (pattern[i]==pattern[j]) {	//������ �Ѻ� ����. 
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
	
	for(int i=0;i<sl;i++){						//�˻���� ���ڿ��� �ε��� i�� ������ ���ư��⸸ ��.  
		while (j > 0 && S[i] != pattern[j]) 	//�ٸ��� ���� 
			j = failTable[j - 1];
		
		if (S[i] == pattern[j]) {			//��ư ��Ī�� �ǰ� �ִ�. 
			if (j == pl - 1) {				//������ ������ �߰����� ��! 
				res.push_back(i - (pl-1)); 	//�信 ������ �߰ߵ� S�� ��ġ�� ���.  
				j = failTable[j];			//failTable �̿��� ȿ�������� ����. 
			}else 							//���� ������ ������ �߰����� ������ ��. 
				j += 1;						//���� ��Ī �õ�. 	
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

	//�˻����ڿ� pattern�� �˻� ��� ���ڿ� S�� ���° ��ġ���� ��Ÿ�������� ��� ����. 
	res = KMP(S, pattern);
	
	cout<<res.size()<<"\n";					//ã�� ������ ���� 
	for (int i = 0; i < res.size(); i++) {	//ã�� ������ ������ġ��(�ε���+1) 
		cout << res[i]+1 << " ";
	}cout << "\n";

}
