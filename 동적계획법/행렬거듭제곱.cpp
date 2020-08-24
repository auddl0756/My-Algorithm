#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll mod=1000000007;

matrix operator * (const matrix& A,const matrix& B){
	int n=A.size();
	matrix C(n,vector<ll>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				C[i][j]+=A[i][k]*B[k][j];
			}
			C[i][j]%=mod;
		}
	}
	return C;
} 

matrix I;

void make_Identity(int n){
	I =matrix(n,vector<ll>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) I[i][j]=1;
			else I[i][j]=0;
		}
	}
}

matrix pow(matrix& A,ll m){
	if(m==0) return I;
	if(m%2>0) return pow(A,m-1)*A;
	//else
	matrix half=pow(A,m/2);
	return half*half;
}

void print(matrix& A){
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[i].size();j++){
			cout<<A[i][j]<<' ';
		}cout<<'\n';
	}cout<<'\n';
}

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin>>n;
	matrix C(2,vector<ll>(2));
	C[0][0]=0, C[0][1]=1 , C[1][0]=1 ,C[1][1]=1;
	
	make_Identity(2);
	
//	print(I);
	
	matrix M_i_1 = pow(C,n-1);
	
//	print(M_i_1);
	
	ll ans= M_i_1[1][1];
	cout<<ans<<'\n';
	
}
