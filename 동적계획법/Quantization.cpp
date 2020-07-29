#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
typedef long long ll;

const int inf=1e9;
vector<int>A;
int n,s,cache[101][11],subSum[101],subSquareSum[101];

//최소제곱오차 계산  
int minError(int lo,int hi){
	int sum,sqSum,m;
	sqSum=subSquareSum[hi]-(lo==0 ? 0:subSquareSum[lo-1]);
	sum=subSum[hi]-(lo==0 ? 0: subSum[lo-1]);
	m=int(0.5 + (double)sum/(hi-lo+1));			//0.5 더하기는 반올림용  
	int ret=sqSum-2*m*sum+m*m*(hi-lo+1);		//미분하면 x가 m일 때, 이 값이 최솟값 나옴. 신기. 
	//cout<<"min error = "<<ret<<"\n";
	return ret;
}

int solve(int from,int parts){
	if(from==n) return 0;
	if(parts==0) return inf;
	
	int& ret= cache[from][parts];
	if(ret!=-1) return ret;
	ret = inf;
	
	for(int partSize=1;from+partSize<=n;partSize++)		//다양한 크기의 조각들로 나눠보며 최소값을 찾아서 cache[from][parts]에 저장한다. 
		ret=min(ret,minError(from,from+partSize-1)+solve(from+partSize,parts-1));
	
	return ret;	
}

//제곱오차 구하기 위해 부분합, 부분제곱합 계산  
void precalc(){
	subSum[0]=A[0];
	subSquareSum[0]=A[0]*A[0];
	
	for(int i=0;i<n;i++){
		subSum[i]=subSum[i-1]+A[i];
		subSquareSum[i]=subSquareSum[i-1]+A[i]*A[i];	
	}
}

//디버깅용  
void print(vector<int>& A){
	for(int i=0;i<A.size();i++)
		cout<<A[i]<<" ";
	cout<<"\n"; 
}

int main(){
	int t;	cin>>t;
	while(t--){
		memset(cache,-1,sizeof(cache));
		memset(subSum,0,sizeof(subSum));
		memset(subSquareSum,0,sizeof(subSquareSum));
		A.clear();
		cin>>n>>s;	A=vector<int>(n); 
		for(int i=0;i<n;i++){
			cin>>A[i];
		} 
		sort(A.begin(),A.end());	//정렬했을 때 같은 숫자로 양자화되는 수들은 서로 인접해 있다 ==> 묶음으로 나누는 문제로 변형 ..! 
		precalc();
		//print(A);
		
		cout<<solve(0,s)<<"\n";
	}
		
} 
