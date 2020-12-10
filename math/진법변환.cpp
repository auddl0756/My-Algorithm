//10진법 -> k진법 
 
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll num; cin>>num;
	int k; cin>>k;
	vector<ll> k_base;
	
	for(;num;){
		k_base.push_back(num%k);
		num/=k;
	}		
	reverse(k_base.begin(),k_base.end());
	for(int i=0;i<k_base.size();i++) cout<<k_base[i]<<" "; cout<<'\n';
	
} 
