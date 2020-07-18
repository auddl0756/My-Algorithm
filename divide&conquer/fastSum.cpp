#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define pii pair<int,int>


//O(n)	일반 선형 알고리즘
int recursiveSum(int  n){
	int ret=0;
	for(int i=1;i<=n;i++) ret+=i;
	return ret;
}


//O(log(n))	분할 정복 알고리즘(반씩 쪼개서..)
int fastSum(int n){
	// base cases (n==1 , n is odd , n is even) 
	if(n==1) return 1;
	if((n%2)==1) return fastSum(n-1)+n;
	return 2*fastSum(n/2)+(n/2)*(n/2);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin>>n;
	cout<<fastSum(n)<<'\n';
			
}

