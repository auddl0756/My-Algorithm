#include <bits/stdc++.h>
#define debug(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";

typedef long long ll;
using namespace std;

/* 의미를 생각하자 */
/* 문제 조건 잘 읽자*/ 

const int MAX=5000;
const int mod=1e9+7;

ll Catalan[MAX+10];		//Catalan[i] : i쌍의 괄호가 잘 짜여지는 방법의 수 
// C[n] = sigma i from 0~n-1 (C[i] *C[n-1-i])
//올바른 괄호의 갯수.
 
void calc_Catalan(){
	Catalan[0]=1;
	for(int i=1;i<=MAX;i++){
		for(int j=0;j<=i-1;j++){
			Catalan[i]+=Catalan[j]*Catalan[i-1-j];
			Catalan[i]%=mod;
		}
	}
}

