// ���װ�� ����ϱ�. nCr ���� �ʹ� Ŀ���� �����÷ο� �߻��� ����. 
// nCr = n-1Cr-1  + n-1Cr :: �ϴ� 1�� �̰� ������ n-1�� �߿��� r-1�� �̰ų� , 1�� �����ϰ� n-1�� �߿��� r�� �̴� ����� �� 

#include <bits/stdc++.h>

using namespace std;
#define pii pair<int,int>
typedef long long ll;


const int MAX=1e9+1e6,MAX2=201;	//MAX = �ʿ��� ���� ���� ���װ�� �ִ�. MAX2= nCr���� n�� �ִ� 
int bino[MAX2][MAX2];

void calc_binomial(){
	for(int i=0;i<MAX2;i++){   		//base cases.
		bino[i][0]=1, bino[i][i]=1;
	}
	for(int i=0;i<MAX2;i++){
		for(int j=1;j<i;j++){		//notice : j�� 1���� ������ ��. 0���� �ϸ� ���װ�� �� ������.  �� i�� �ۿ� ���µ� i���� ���� j�� ������ ����. 
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
