#include <iostream>
#include <string>
#include <vector>

using namespace std;

//낮은 자리수부터 벡터에 담아야 계산 구현하기 편함 
vector<int> stoVec(string s){
	vector<int> ret;
	for(int i=s.size()-1;i>=0;i--)
		ret.push_back(s[i]-'0');
	return ret;
}


//자리 올림 처리
void normalize(vector<int>& C){
	C.push_back(0);
	for(int i=0;i<C.size()-1;i++){
		if(C[i]<0){
			int borrow = (abs(C[i]+9)/10;
			C[i+1]-=borrow;
			C[i]+=10*borrow;
		}else{
			C[i+1] +=(C[i]/10);
			C[i]%=10;
		}
	}
	while(C.size()>1 && C.back()==0) C.pop_back();
}


vector<int> multiply(vector<int>& A,vector<int>& B){
	vector<int> C(A.size()+B.size()+1,0);
	for(int i=0;i<A.size();i++){
		for(int j=0;j<B.size();j++){
			C[i+j]+=A[i]*B[j];
		}
	}
	normalize(C);
	return C;

	
}

int main(){
	string a,b;
	cin>>a>>b;

	vector<int> A = stoVec(a);
	vector<int> B = stoVec(b);

	vector<int> C = multiply(A,B);	// 낮은 자리수부터 담겨있다.
	for(int i=C.size()-1;i>=0;i--)
		cout<<C[i];
	cout<<"\n";
}
