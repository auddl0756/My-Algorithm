#include <bits/stdc++.h>

#define debug(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
//#define sorta(a) sort(a.begin(),a.end());

//typedef long long ll;
using namespace std;


//최악의 경우 O(N*N) ==> ps에선 쓸 일 없음. 
void quickSort(vector<int>& a,int left,int right){
	int l=left,r=right;
	int mid=(l+r)/2;		
	int pivot =a[mid];		//set pivot as value at mid index
	
	for(;l<r;){
		for(;a[l]<pivot;) l++;
		for(;a[r]>pivot;) r--;
		
		if(l<=r){
			swap(a[l],a[r]);
			l++,r--;
		}
	}
	
	if(left<r) quickSort(a,left,r);
	if(right>l) quickSort(a,l,right);
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	quickSort(n,a);
}	





