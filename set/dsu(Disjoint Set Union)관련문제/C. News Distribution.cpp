#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define ppi pair<pair<int,int>,int>
#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta2(a,n) sort(a,a+n);

#define p(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define p2(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";

#define all(v) (v).begin(), (v).end()
#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define fi first
#define se second

typedef long long ll;

const int MAX=5*100001;

class Set{
private:
 int parent[MAX];				//for maintaining group's header
 int sz[MAX];					//for maingtaining group's size
 
public:
 Set(){
	for(int i=0;i<MAX;i++){
	   parent[i]=i;
	   sz[i]=1;
	}
 }
 
 int find(int idx){
  if(idx==parent[idx]) return idx;
  return parent[idx]=find(parent[idx]);
 }

 void merge(int idx1,int idx2){
  int p1,p2;
  p1=find(idx1); p2=find(idx2);
  if(p1==p2) return;
  
  parent[p1]=p2;
  sz[p2]+=sz[p1];				//add group's size to parent group's size
 }
 
 int getsize(int idx){			//find group's size
 	int parent_idx = find(idx);
 	return sz[parent_idx];
 }
 
 void print(){			///for debugging.
 	p2(parent,20);
 	p2(sz,20);
 }
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	Set *s=new Set();		//use as pointer
	
	int n,m,k; cin>>n>>m;
	for(int g=1;g<=m;g++){
		cin>>k;
		vector<int> tmp(k);
		for(int i=0;i<k;i++){
			 cin>>tmp[i]; tmp[i]--;
		}

		sorta(tmp);
		for(int i=0;i<k-1;i++){
			int p1,p2; p1=s->find(tmp[i]), p2=s->find(tmp[i+1]);
			//cout<<p1<<" "<<p2<<"\n";
			s->merge(p2,p1);
		}
	}
	
	//s->print();
	for(int i=0;i<n;i++){
		cout<<s->getsize(i)<<" ";
	}cout<<'\n';
	
}
	

