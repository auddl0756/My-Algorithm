#include <iostream>
#include <string>

using namespace std;
#define pii pair<int,int>

template <typename T>		

T sum(T a,T b){
	return a+b;
}

template <typename T1,typename T2>

void print(T1 a,T2 b){
	cout<<a<<"\n";
	cout<<b<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a,b;
	a="abcd",b="efgh";
	
	cout<<sum<string>(a,b)<<"\n";
	
	print(a,b);
	print(a,12);
}

