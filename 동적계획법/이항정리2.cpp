// 이항계수 계산하기. nCr 값이 너무 커져서 오버플로우 발생에 주의. 
// nCr = n-1Cr-1  + n-1Cr :: 일단 1개 뽑고 나머지 n-1개 중에서 r-1개 뽑거나 , 1개 배제하고 n-1개 중에서 r개 뽑는 경우의 합 

#include <bits/stdc++.h>

using namespace std;
#define pii pair<int,int>
typedef long long ll;


const int MAX=1e9+1e6,MAX2=201;	//MAX = 필요한 범위 내의 이항계수 최댓값. MAX2= nCr에서 n의 최댓값 
int bino[MAX2][MAX2];

void calc_binomial(){
	for(int i=0;i<MAX2;i++){   		//base cases.
		bino[i][0]=1, bino[i][i]=1;
	}
	for(int i=0;i<MAX2;i++){
		for(int j=1;j<i;j++){		//notice : j는 1부터 돌려야 함. 0부터 하면 이항계수 안 구해짐.  또 i개 밖에 없는데 i보다 많이 j개 뽑으면 오류. 
			bino[i][j]= min(MAX,bino[i-1][j] + bino[i-1][j-1]);
		}
	}
}

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(0);	
	calc_binomial();
	
	int n,r; cin>>n>>r;
	cout<<bino[n][r]<<"\n";
}
