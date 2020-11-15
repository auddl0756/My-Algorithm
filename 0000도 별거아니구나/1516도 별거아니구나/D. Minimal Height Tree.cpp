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
#define lb(arr,num) lower_bound(all(arr),num)

#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define msi map<string,int>

typedef long long ll;
using namespace std;

#define pll pair<ll,ll>
#define pcc pair<char,char>

const int MAX=200100;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	int Q,n; cin>>Q;
	while(Q--){
		cin>>n;
		vector<int> order(n);
		vector<int> lowest_height(n,0);
		for(int i=0;i<n;i++) cin>>order[i];
		
//		if(n==1){
//			cout<<0<<"\n"; continue;
//		}
		
		int height=0;
		for(int i=1;i<n;i++){
			if(order[i-1]>order[i]){
				height++;
			}
			lowest_height[i]=lowest_height[height]+1;		//dp... 진짜 간단한 거였네.. 
		}
		
		cout<<lowest_height[n-1]<<"\n";
	}
	
	//debug2(lowest_height,n+1);
	
}	



//******* BELOW IS WRONG LOGIC***********
//int height=1;
//for(int i=1;i<n-1;i++){
//	if(order[i]>order[i+1]){
//		height++;
//	}
//}
//cout<<height<<"\n";



 


