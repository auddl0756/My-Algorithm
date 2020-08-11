#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta(a,n) sort(a,a+n);
#define p(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define p(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";
typedef long long ll;

//count(begin, end, value)
//[begin, end)에 포함되어 있는 원소 중에서 value의 개수를 찾는다  

//count_if(begin, end, p)
//[begin, end)에 포함되어 있는 원소 중에서 조건 p에 해당하는 것의 개수를 찾음 

//  O(N) 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<int> A={1,1,1,1,2,2,2,3,3,4};
	cout<<"1의 갯수 = "<<count(A.begin(),A.end(),1)<<"\n"; 
	
	int odd =count_if(A.begin(),A.end(),[](int x){
		return x%2==1;
	});
	
	int even = count_if(A.begin(),A.end(),
				[](int x){return x%2==0;});
	
	int under_3 =count_if(A.begin(),A.end(),
				[](int x){return x<3;});
	
	cout<<odd<<" "<<even<<" "<<under_3<<"\n";
	
	string s="abbccc";
	
	cout<< count(s.begin(),s.end(),'b')<<"\n"; 
}
