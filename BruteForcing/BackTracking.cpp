#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define pii pair<int,int>

//출력용  
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
	
	// 조합이므로 지나온 곳은 다시 보지 않는다. 
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
	
	//순열이기 때문에 지나온 곳을 다시 봐야한다.
	//하지만 중복으로 선택하느 것을 방지하기 위해 selected를 두어야 한다. 
	for(int next=0;next<n;next++){
		if(selected[next]) continue;
		selected[next]=true;
		picked.push_back(next);
		
		pick2(n,picked,toPick-1);
		
		selected[next]=false;
		picked.pop_back();
		
	}
}


//중복 조합 ,nHr 
void pick3(int n,vector<int>&picked,int toPick,int start){		
//add argument "start" to avoid duplicated... it is main difference between 중복 순열 
	if(toPick==0){
		print(picked);
		return;
	}
	 
	for(int next=start;next<n;next++){
		picked.push_back(next);
		//pick3(n,picked,toPick-1,start);  //next옜 옜옜옜옜 옜� 옜 옜� start 옜 옜옜�. 옜 옜.
		pick3(n.picked,toPick-1,next);   
		picked.pop_back();
	}
}
 

//중복 순열. :: 그냥 막 뽑으면 됨  
void pick4(int n,vector<int>&picked,int toPick){
	if(toPick==0){
		print(picked);
		return;
	}
	//int smallest=picked.empty()? 0:picked.back()+1;
	
	//언제나 처음부터 뽑기 시작하므로.. 
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
	
//조합, nCr 
	//pick1(n,picked,r);
	
//순열, nPr
	//pick2(n,picked,r);
	
//중복조합 ,nHr
	//pick3(n,picked,r,0); 
	//cout<<"\n\n";
	
//중복순열
	//pick4(n,picked,r); 
	
}



