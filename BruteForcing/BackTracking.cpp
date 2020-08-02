#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define pii pair<int,int>

//��¿�  
void print(vector<int>&picked){
	for(int i=0;i<picked.size();i++)
	cout<<picked[i]<<" ";
	cout<<"\n";
}
 

//combinations, nCr
void pick1(int n,vector<int>&picked,int toPick){
	if(toPick==0){
		print(picked);
		return;
	}
	int smallest=picked.empty()? 0:picked.back()+1;
	
	// �����̹Ƿ� ������ ���� �ٽ� ���� �ʴ´�. 
	for(int next=smallest;next<n;next++){
		picked.push_back(next);
		pick1(n,picked,toPick-1);
		picked.pop_back();
	}
}

//permutations , nPr
const int MAX=27;	//for example, small letter alphabet 
bool selected[MAX];
void pick2(int n,vector<int>&picked,int toPick){
	if(toPick==0){
		print(picked);
		return;
	}
	
	//�����̱� ������ ������ ���� �ٽ� �����Ѵ�.
	//������ �ߺ����� �����ϴ� ���� �����ϱ� ���� selected�� �ξ�� �Ѵ�. 
	for(int next=0;next<n;next++){
		if(selected[next]) continue;
		selected[next]=true;
		picked.push_back(next);
		
		pick2(n,picked,toPick-1);
		
		selected[next]=false;
		picked.pop_back();
		
	}
}


//�ߺ� ���� ,nHr 
void pick3(int n,vector<int>&picked,int toPick,int start){		
//add argument "start" to avoid duplicated... it is main difference between �ߺ� ���� 
	if(toPick==0){
		print(picked);
		return;
	}
	 
	for(int next=start;next<n;next++){
		picked.push_back(next);
		//pick3(n,picked,toPick-1,start);  //next�� �������� ��� �� ��� start �� �����. �� ��.
		pick3(n.picked,toPick-1,next);   
		picked.pop_back();
	}
}
 

//�ߺ� ����. :: �׳� �� ������ ��  
void pick4(int n,vector<int>&picked,int toPick){
	if(toPick==0){
		print(picked);
		return;
	}
	//int smallest=picked.empty()? 0:picked.back()+1;
	
	//������ ó������ �̱� �����ϹǷ�.. 
	for(int next=0;next<n;next++){
		picked.push_back(next);
		pick4(n,picked,toPick-1);
		picked.pop_back();
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n,r;
	vector<int>picked;
	cin>>n>>r;
	
//����, nCr 
	//pick1(n,picked,r);
	
//����, nPr
	//pick2(n,picked,r);
	
//�ߺ����� ,nHr
	//pick3(n,picked,r,0); 
	//cout<<"\n\n";
	
//�ߺ�����
	//pick4(n,picked,r); 
	
}



