#include <bits/stdc++.h>

using namespace std;

const int MAX=1e6;

string S;
int n,gap,suffix_array[MAX],group[MAX];
int temp[MAX];
int LCP[MAX];

bool comp(int i,int j){
	if(group[i] != group[j]) return group[i] <group[j];		//같은 그룹일 때  
	
	//그룹이 다를 때  
	i+=gap; j+=gap;
	return (i<n && j<n) ? (group[i]<group[j]) : (i>j);		//i >j 의문... 
}

void build_suffix_array(){
	n=S.size();
	//초기화  
	for(int i=0;i<n;i++){
		suffix_array[i]=i;
		group[i]=S[i];	//처음엔 첫 글자로 비교하기 위해  
	}
	
	for(gap=1;;gap*=2){
		sort(suffix_array,suffix_array+n,comp);			// gap 글자만큼만 보고 정렬  
		
		memset(temp,0,sizeof(int)*MAX);
		
		for(int i=0;i<n-1;i++) temp[i+1]=temp[i] + comp(suffix_array[i],suffix_array[i+1]);		//그룹 넘버링  
		
		for(int i=0;i<n;i++) group[suffix_array[i]]=temp[i];		//복사  
		
		if(temp[n-1]==n-1) break;	//모두 그룹이 나눠졌으면 종료  
		
	}	
}

void build_LCP(){
	//인덱스 i부터 시작하는 접미사와 인접한 다음 접미사는 인덱스 suffix_array[group[i]+1]부터 시작하는 접미사이다. 
	for(int i=0,k=0;i<n;i++,k=max(k-1,0)){
	//for(int i=0,k=0;i<n;i++){
		if(group[i]==n-1) continue;
		//k=0;
		for(int j=suffix_array[group[i]+1];S[i+k]==S[j+k];k++);		//j = 다음 그룹의 suffix array  
		
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
