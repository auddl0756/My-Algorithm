#include <bits/stdc++.h>

using namespace std;

const int MAX=1e6;

string S;
int n,gap,suffix_array[MAX],group[MAX];
int temp[MAX];
int LCP[MAX];

bool comp(int i,int j){
	if(group[i] != group[j]) return group[i] <group[j];		//���� �׷��� ��  
	
	//�׷��� �ٸ� ��  
	i+=gap; j+=gap;
	return (i<n && j<n) ? (group[i]<group[j]) : (i>j);		//i >j �ǹ�... 
}

void build_suffix_array(){
	n=S.size();
	//�ʱ�ȭ  
	for(int i=0;i<n;i++){
		suffix_array[i]=i;
		group[i]=S[i];	//ó���� ù ���ڷ� ���ϱ� ����  
	}
	
	for(gap=1;;gap*=2){
		sort(suffix_array,suffix_array+n,comp);			// gap ���ڸ�ŭ�� ���� ����  
		
		memset(temp,0,sizeof(int)*MAX);
		
		for(int i=0;i<n-1;i++) temp[i+1]=temp[i] + comp(suffix_array[i],suffix_array[i+1]);		//�׷� �ѹ���  
		
		for(int i=0;i<n;i++) group[suffix_array[i]]=temp[i];		//����  
		
		if(temp[n-1]==n-1) break;	//��� �׷��� ���������� ����  
		
	}	
}

void build_LCP(){
	//�ε��� i���� �����ϴ� ���̻�� ������ ���� ���̻�� �ε��� suffix_array[group[i]+1]���� �����ϴ� ���̻��̴�. 
	for(int i=0,k=0;i<n;i++,k=max(k-1,0)){
	//for(int i=0,k=0;i<n;i++){
		if(group[i]==n-1) continue;
		//k=0;
		for(int j=suffix_array[group[i]+1];S[i+k]==S[j+k];k++);		//j = ���� �׷��� suffix array  
		
		LCP[group[i]+1]=k;	
	}
}

void print(){		//print suffix array , groups , LCP
	for(int i=0;i<n;i++)
		cout<<suffix_array[i]+1<<" ";
	cout<<"\n";

	for(int i=0;i<n;i++)
		cout<<group[i]<<" ";
	cout<<"\n";	

	cout<<'x'<<" ";
	for(int i=1;i<n;i++)
		cout<<LCP[i]<<" ";
	cout<<"\n";	
}

int main(){
	cin>>S;
	
	build_suffix_array();

	build_LCP();
	
	//print();
	 

	
}
