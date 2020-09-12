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

//문자에 대한 후위 표기식. 
//수에 대한 표기식은 좀 추가해야 함. 

map<char,int> priorities;

void init_priority(){
	priorities['(']=0; priorities[')']=0;
	priorities['+']=1; priorities['-']=1;
	priorities['*']=2; priorities['/']=2;	
}

string infix_to_postfix(string expr){
	string postfix="";
	stack<char> st;
	
	for(char e:expr){
		if((e>='A' && e<='Z') || (e>='a' && e<='z')) {
			postfix+=e; continue;
		} 
		
		if(e=='('){
			st.push(e); continue;
		}
		
		if(e==')'){
			while(true){
				char peek=st.top();
				if(peek!='(') postfix+=peek, st.pop();
				else{
					st.pop(); break;
				}
			}
		}
		
		if(e=='+' || e=='-' || e=='*' || e=='/'){
			int now_priority = priorities[e];
			while(true){
				if(st.empty()) break;
				
				char peek=st.top();
				int next_priority =priorities[peek];
				if(next_priority < now_priority) break;
				
				postfix+=peek;
				st.pop();
			}
			
			st.push(e);
		}	
	}
	
	while(not st.empty()){		//남은 것들. 
		postfix+=st.top(); st.pop();
	}
	return postfix;
}

int main(){
	string expression; cin>>expression;
	
	init_priority();
	
	string postfix=infix_to_postfix(expression);
	
	cout<<postfix<<"\n";
	
} 
