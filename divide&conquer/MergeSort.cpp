#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define pii pair<int,int>
typedef long long ll;
const int MAX=500001;

vector<int>A;
int tmp[MAX];	//임시 배열.. 정렬된 값을 잠깐 담고 있을..  

void merge(int l,int r){
	int mid =(l+r)/2;
	int L,R,K;
	L=l;	R=mid+1;	K=l;
	
	while(L<=mid && R<=r)
		tmp[K++] = A[L] <= A[R] ? A[L++] :A[R++];		// 오름차순 정렬  
	
	//남은 것들 배열에 넣어주기  
	if(L>mid)
		for(int i=R;i<=r;i++)
			tmp[K++]=A[i];
	else
		for(int i=L;i<=mid;i++)
			tmp[K++]=A[i];
	
	//정렬된 tmp 배열을 원본 배열인 A에 복사해주기  
	for(int i=l;i<=r;i++)
		A[i]=tmp[i];

}

//쪼개는 과정.. 
void divide(int l,int r){
	if(l==r) return;		//다 쪼갰을 때 
	
	int mid = (l+r)/2;
	divide(l,mid);		//좌 
	divide(mid+1,r);	//우 
	merge(l,r);			//좌,우로 다 쪼개고 나면 합치기 call :: log(N)번.. 
}

void mergeSort(int l,int r){
	divide(l,r);	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin>>n;
	A=vector<int>(n,0);
	for(int i=0;i<n;i++) cin>>A[i];
	
	mergeSort(0,n-1); 
	
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<"\n";
	
}

