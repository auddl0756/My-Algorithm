#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define pii pair<int,int>

//Ãâ·Â¿ë  
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
	
	// Á¶ÇÕÀÌ¹Ç·Î Áö³ª¿Â °÷Àº ´Ù½Ã º¸Áö ¾Ê´Â´Ù. 
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
	
	//¼ø¿­ÀÌ±â ¶§¹®¿¡ Áö³ª¿Â °÷À» ´Ù½Ã ºÁ¾ßÇÑ´Ù.
	//ÇÏÁö¸¸ Áßº¹À¸·Î ¼±ÅÃÇÏ´À °ÍÀ» ¹æÁöÇÏ±â À§ÇØ selected¸¦ µÎ¾î¾ß ÇÑ´Ù. 
	for(int next=0;next<n;next++){
		if(selected[next]) continue;
		selected[next]=true;
		picked.push_back(next);
		
		pick2(n,picked,toPick-1);
		
		selected[next]=false;
		picked.pop_back();
		
	}
}


//Áßº¹ Á¶ÇÕ ,nHr 
void pick3(int n,vector<int>&picked,int toPick,int start){		
//add argument "start" to avoid duplicated... it is main difference between Áßº¹ ¼ø¿­ 
	if(toPick==0){
		print(picked);
		return;
	}
	 
	for(int next=start;next<n;next++){
		picked.push_back(next);
		//pick3(n,picked,toPick-1,start);  //next¿¿ ¿¿¿¿¿¿¿¿ ¿¿¿ ¿¿ ¿¿¿ start ¿¿ ¿¿¿¿¿. ¿¿ ¿¿.
		pick3(n.picked,toPick-1,next);   
		picked.pop_back();
	}
}
 

//Áßº¹ ¼ø¿­. :: ±×³É ¸· »ÌÀ¸¸é µÊ  
void pick4(int n,vector<int>&picked,int toPick){
	if(toPick==0){
		print(picked);
		return;
	}
	//int smallest=picked.empty()? 0:picked.back()+1;
	
	//¾ðÁ¦³ª Ã³À½ºÎÅÍ »Ì±â ½ÃÀÛÇÏ¹Ç·Î.. 
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
	
//Á¶ÇÕ, nCr 
	//pick1(n,picked,r);
	
//¼ø¿­, nPr
	//pick2(n,picked,r);
	
//Áßº¹Á¶ÇÕ ,nHr
	//pick3(n,picked,r,0); 
	//cout<<"\n\n";
	
//Áßº¹¼ø¿­
	//pick4(n,picked,r); 
	
}



