#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define pii pair<int,int>
typedef long long ll;
const int MAX=500001;

vector<int>A;
int tmp[MAX];	//�ӽ� �迭.. ���ĵ� ���� ��� ��� ����..  

void merge(int l,int r){
	int mid =(l+r)/2;
	int L,R,K;
	L=l;	R=mid+1;	K=l;
	
	while(L<=mid && R<=r)
		tmp[K++] = A[L] <= A[R] ? A[L++] :A[R++];		// �������� ����  
	
	//���� �͵� �迭�� �־��ֱ�  
	if(L>mid)
		for(int i=R;i<=r;i++)
			tmp[K++]=A[i];
	else
		for(int i=L;i<=mid;i++)
			tmp[K++]=A[i];
	
	//���ĵ� tmp �迭�� ���� �迭�� A�� �������ֱ�  
	for(int i=l;i<=r;i++)
		A[i]=tmp[i];

}

//�ɰ��� ����.. 
void divide(int l,int r){
	if(l==r) return;		//�� �ɰ��� �� 
	
	int mid = (l+r)/2;
	divide(l,mid);		//�� 
	divide(mid+1,r);	//�� 
	merge(l,r);			//��,��� �� �ɰ��� ���� ��ġ�� call :: log(N)��.. 
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

